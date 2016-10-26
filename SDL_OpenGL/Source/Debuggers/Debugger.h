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
	Debugger() {}

	// "= delete" - C++11. Prevents compiler from generating these functions.
	Debugger(const Debugger&) = delete;
	Debugger& operator=(const Debugger&) = delete;
	
	static Debugger& GetInstance();

	void Debugger::Log_(const char* InFilePath, int InLineNumber, DebugType InDebugType, const char* InMessage, ...);

};