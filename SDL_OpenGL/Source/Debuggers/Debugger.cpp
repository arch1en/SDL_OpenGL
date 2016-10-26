
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
#ifdef PLATFORM_WINDOWS
	int Foreground = 15;
#endif

	if (InDebugType == DebugType::EDT_Notice)
	{
#ifdef PLATFORM_WINDOWS
		int Color = Foreground + Background * 16;
		
		SetConsoleTextAttribute(hConsole, Color);
#endif
		DebugTypeString = "Notice";
	}
	else if (InDebugType == DebugType::EDT_Warning)
	{
#ifdef PLATFORM_WINDOWS
		Foreground = 14;
		int Color = Foreground + Background * 16;
		
		SetConsoleTextAttribute(hConsole, Color);
#endif
		DebugTypeString = "Warning";
	}
	else if (InDebugType == DebugType::EDT_Error)
	{
#ifdef PLATFORM_WINDOWS
		Foreground = 12;
		int Color = Foreground + Background * 16;
		
		SetConsoleTextAttribute(hConsole, Color);
#endif
		DebugTypeString = "Error";
	}
	else if (InDebugType == DebugType::EDT_Fatal)
	{
#ifdef PLATFORM_WINDOWS
		Foreground = 12;
		int Color = Foreground + Background * 16;
		
		SetConsoleTextAttribute(hConsole, Color);
#endif
		DebugTypeString = "Fatal";
	}
	else
	{
		DebugTypeString = "Undefined";
	}

	std::string String;

	while (*InMessage != '\0')
	{
		const char* test = InMessage + 1;

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
#ifdef PLATFORM_WINDOWS
	if (Foreground != 15)
	{
		SetConsoleTextAttribute(hConsole, DefaultConsoleColor);
	}
#endif
}