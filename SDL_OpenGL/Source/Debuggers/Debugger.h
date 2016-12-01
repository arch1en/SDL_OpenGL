////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Debugging tool, for using Log messages, and future similar mechanisms.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "stdafx.h"

#define Log(DebugType, Message, ...) Debugger::GetInstance().Log_( __FILE__, __LINE__, DebugType, Message, __VA_ARGS__);

enum class DebugType : uint8_t
{
	EDT_Notice,
	EDT_Warning,
	EDT_Error,
	EDT_Fatal,
	EDT_Total		// U can't touch this ! (HAMMER TIME)
};

class Debugger
{
public:
	Debugger();

	// "= delete" - C++11. Prevents compiler from generating these functions.
	Debugger(const Debugger&) = delete;
	Debugger& operator=(const Debugger&) = delete;
	
	static Debugger& GetInstance();

	void Debugger::Log_(const char* InFilePath, int InLineNumber, DebugType InDebugType, const char* InMessage, ...);

private:

#ifdef PLATFORM_WINDOWS
	HANDLE hConsole;
	int Background = 0;
	int DefaultConsoleColor = 15 + 0 * 16;
#endif

	void CreateLogFile();
	void SaveLogToFile();
	
	/**
	*   Changes text color on the console. Platform specific.
	*
	*   @param  InForeground    : Sets foreground color of a text (default 15 = White).
	*   @param  InBackground    : Sets background color of a text (default 0 = Black).
	*
	*/
	void SetMessageColor(int InForeground = 15, int InBackground = 0);
};