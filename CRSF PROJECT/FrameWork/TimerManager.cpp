#include "TimerManager.h"

void TimerManager::TimerInit()
{
	stage = false;
	startTime = clock();

	stageTime.index = 0;

}

void TimerManager::TimerRelease()
{
	playTime.clear();
	waitTime.clear();
}

bool TimerManager::Tick(int frame)
{
	oldTime = clock();

	while (true)
	{
		curTime = clock();
		endTime = clock();
		if (stage)
		{
			stageTime.endTime = clock();

			if ((stageTime.endTime - stageTime.startTime) / CLOCKS_PER_SEC > stageTime.timer)
			{
				stage = false;
			}
		}

		for (itWaitTime = waitTime.begin(); itWaitTime != waitTime.end(); itWaitTime++)
		{
			itWaitTime->second.waitEndTime = clock();
			// 0.01 sec delay
			if (((itWaitTime->second.waitEndTime - itWaitTime->second.waitStartTime) / CLOCKS_PER_SEC) - 0.1f > itWaitTime->second.timer)
			{
				itWaitTime->second.waitStartTime = clock();
			}
		}

		for (int i = 0;i < playTime.size() ;i++)
		{
			playTime[i].endTime = clock();
		}
	
		if (curTime - oldTime > frame)
		{
			return true;
		}
	}

	return false;
}

void TimerManager::StartStageTimer(double timer)
{
	stage = true;
	stageTime.startTime = clock();
	stageTime.timer = timer;
}

void TimerManager::StopStageTimer()
{
	stage = false;
}

double TimerManager::GetStageTimer()
{
	return ((double)stageTime.endTime - (double)stageTime.startTime) / CLOCKS_PER_SEC;
}

bool TimerManager::StateStageTimer()
{
	return stage;
}

bool TimerManager::TickPlayTimer(int index, double playDefault)
{

	if (playDefault != -1)
	{
		playTime[index].timer = playDefault;
	}

	if ((((double)playTime[index].endTime - (double)playTime[index].startTime) / CLOCKS_PER_SEC) > playTime[index].timer)
	{

		playTime[index].startTime = clock();
		return true;
	}

	return false;
}

void TimerManager::AddPlayTimer(int index, double timer)
{
	if (index > playTime.size()) return;

	_SCLOCK newClock;

	newClock.index = index;
	newClock.startTime = clock();
	newClock.endTime = 0.0f;
	newClock.timer = (clock_t)timer;

	playTime.push_back(newClock);


}

void TimerManager::ClearPlayTimer()
{
	playTime.clear();
}

bool TimerManager::TickWaitTimer(double time)
{
	if (!(waitTime.find(time) != waitTime.end()))
	{
		AddWaitTimer(time);
	}
	else
	{
		map<double, _SWaitClock>::iterator map = waitTime.find(time);

		if (((double)(map->second.waitEndTime - map->second.waitStartTime) / CLOCKS_PER_SEC) > time)
		{
			//map->second.waitStartTime = clock();
			waitTime.erase(map);

			return true;
		}
	}

	return false;
}

void TimerManager::AddWaitTimer(double time)
{
	if (!(waitTime.find(time) != waitTime.end()))
	{
		_SWaitClock clock;

		clock.waitStartTime = 0.0f;
		clock.waitEndTime = 0.0f;
		clock.timer = time;

		waitTime.insert(pair<double, _SWaitClock>(time, clock));
	}
}

void TimerManager::ClearWaitTimer()
{
	waitTime.clear();
}

double TimerManager::GetPlayTime(int index)
{
	return playTime[index].timer;
}


double TimerManager::GetGameTime()
{
	return ((double)endTime - (double)startTime) / CLOCKS_PER_SEC;
}

double TimerManager::GetFrame()
{
	return ((double)curTime - (double)oldTime);
}
