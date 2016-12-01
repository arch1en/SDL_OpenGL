////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Debugging class for measuring time between functions. Singleton.
//  @version    : 1.0.0
//
////////////////////////////////////////

#pragma once

#include "stdafx.h"
#include <ctime>

class DebugTimer
{
public:

	static DebugTimer& GetInstance();

	void Start();
	void Stop();
	double Check();

	void ShowResult();

private:

	DebugTimer() {}
	~DebugTimer() {}

	clock_t StartTime;
	clock_t StopTime;
	double DifferenceTime;
};