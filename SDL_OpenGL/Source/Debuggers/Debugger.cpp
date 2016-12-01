////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Debugging tool, for using Log messages, and future similar mechanisms.
//  @version    : 1.0.0
//
////////////////////////////////////////
#include "Debugger.h"

#include <string>

Debugger::Debugger()
{
#ifdef PLATFORM_WINDOWS
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}

Debugger& Debugger::GetInstance()
{
	static Debugger Singleton;
	return Singleton;
}

void Debugger::Log_(const char* InFilePath, int InLineNumber, DebugType InDebugType, const char* InMessage, ...)
{
	va_list Arguments;
	va_start(Arguments, InMessage);

	const char* DebugTypeString;

	if (InDebugType == DebugType::EDT_Notice)
	{
		SetMessageColor();
		DebugTypeString = "Notice";
	}
	else if (InDebugType == DebugType::EDT_Warning)
	{
		SetMessageColor(14);
		DebugTypeString = "Warning";
	}
	else if (InDebugType == DebugType::EDT_Error)
	{
		SetMessageColor(12);
		DebugTypeString = "Error";
	}
	else if (InDebugType == DebugType::EDT_Fatal)
	{
		SetMessageColor(12);
		DebugTypeString = "Fatal";
	}
	else
	{
		DebugTypeString = "Undefined";
	}

	std::string String;

	while (*InMessage != '\0')
	{
		if (*InMessage == '/')
		{
			String += *(InMessage + 1);
		}
		else if (*InMessage == '%')
		{

			InMessage++;

			if (*InMessage == 's')
			{
				String.append(va_arg(Arguments, const char*));

			}
			else if (*InMessage == 'i' || *InMessage == 'd')
			{
				std::string Buffer = std::to_string(va_arg(Arguments, int));
				String.append(Buffer);
			}
			else if (*InMessage == 'f')
			{
				std::string Buffer = std::to_string(va_arg(Arguments, double));
				String.append(Buffer);
			}
		}
		else
		{
			String += *InMessage;
		}

		InMessage++;

	}

	if (InDebugType < DebugType::EDT_Error)
	{
		printf("%s : %s\n", DebugTypeString, String.c_str());
	}
	else
	{
		printf("%s : %s | In %s Line (%i)\n", DebugTypeString, String.c_str(), InFilePath, InLineNumber);
	}
	
	if (InDebugType > DebugType::EDT_Notice)
	{
		SetMessageColor();
	}
}

void Debugger::CreateLogFile()
{
	// TODO : Implement log file creating according to DebuggingProperties.ini file.
}

void Debugger::SaveLogToFile()
{
	// TODO : Implement log file creating according to DebuggingProperties.ini file.
}

void Debugger::SetMessageColor(int InForeground, int InBackground)
{
#ifdef PLATFORM_WINDOWS
	int Color = InForeground + InBackground * 16;

	SetConsoleTextAttribute(hConsole, Color);
#endif
}