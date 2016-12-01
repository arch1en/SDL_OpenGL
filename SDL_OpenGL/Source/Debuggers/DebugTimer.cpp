////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Debugging class for measuring time between functions. Singleton.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "DebugTimer.h"

DebugTimer& DebugTimer::GetInstance()
{
	static DebugTimer Instance;
	return Instance;
}

void DebugTimer::Start()
{
	StartTime = std::clock();
}

void DebugTimer::Stop()
{
	StopTime = std::clock();

}

double DebugTimer::Check()
{
	if (StartTime <= 0.0 || StopTime <= 0.0)
	{
		return 0.0;
	}

	return StopTime - StartTime;
}

void DebugTimer::ShowResult()
{
	double Difference = Check();
	if (Difference > 0.0)
	{
		printf("Time Difference : %f ms", Check());
	}
	else
	{
		printf("Cannot read time difference.");
	}
}
