#pragma once
#include "singleton.h"

#include <vector>
#include <map>
#include <time.h>

using namespace std;

class TimerManager : public singleton<TimerManager>
{
	struct _SWaitClock {
		double waitStartTime;
		double waitEndTime;
		double timer;
	};
	
	struct _SCLOCK {
		int index;
		clock_t startTime;
		clock_t endTime;
		double timer;
	};

private:
	clock_t curTime;
	clock_t oldTime;

	// 플레이 게임 타이머
	clock_t startTime;
	clock_t endTime;

	// 스테이지 시작
	bool stage;
	_SCLOCK stageTime;

	// 시간 변하는 값
	vector<_SCLOCK> playTime;
	vector<_SCLOCK>::iterator itPlayTime;

	// 기다리는 값 저장
	map<double, _SWaitClock> waitTime;
	map<double, _SWaitClock>::iterator itWaitTime;

public:
	void TimerInit();
	void TimerRelease();

	bool Tick(int frame);

	// Stage 시간
	void StartStageTimer(double timer);
	void StopStageTimer();
	double GetStageTimer();
	bool StateStageTimer();

	// 가변되는 시간
	bool TickPlayTimer(int index, double playDefault = -1);
	void AddPlayTimer(int index, double timer);
	void ClearPlayTimer();

	// 저장되는 시간
	bool TickWaitTimer(double time);
	void AddWaitTimer(double time);
	void ClearWaitTimer();


	double GetPlayTime(int index);

	double GetGameTime();
	double GetFrame();

};

