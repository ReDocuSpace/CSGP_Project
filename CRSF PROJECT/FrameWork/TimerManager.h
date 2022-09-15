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

	// �÷��� ���� Ÿ�̸�
	clock_t startTime;
	clock_t endTime;

	// �������� ����
	bool stage;
	_SCLOCK stageTime;

	// �ð� ���ϴ� ��
	vector<_SCLOCK> playTime;
	vector<_SCLOCK>::iterator itPlayTime;

	// ��ٸ��� �� ����
	map<double, _SWaitClock> waitTime;
	map<double, _SWaitClock>::iterator itWaitTime;

public:
	void TimerInit();
	void TimerRelease();

	bool Tick(int frame);

	// Stage �ð�
	void StartStageTimer(double timer);
	void StopStageTimer();
	double GetStageTimer();
	bool StateStageTimer();

	// �����Ǵ� �ð�
	bool TickPlayTimer(int index, double playDefault = -1);
	void AddPlayTimer(int index, double timer);
	void ClearPlayTimer();

	// ����Ǵ� �ð�
	bool TickWaitTimer(double time);
	void AddWaitTimer(double time);
	void ClearWaitTimer();


	double GetPlayTime(int index);

	double GetGameTime();
	double GetFrame();

};

