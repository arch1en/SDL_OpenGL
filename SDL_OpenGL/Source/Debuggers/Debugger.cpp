
#include "Debugger.h"

#include <string>

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
		DebugTypeString = "Notice";
	}
	else if (InDebugType == DebugType::EDT_Warning)
	{
		DebugTypeString = "Warning";
	}
	else if (InDebugType == DebugType::EDT_Error)
	{
		DebugTypeString = "Error";
	}
	else if (InDebugType == DebugType::EDT_Fatal)
	{
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
}