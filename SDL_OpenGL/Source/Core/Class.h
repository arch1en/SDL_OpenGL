////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @author     : Artur Ostrowski
//  @usage      : Base type for all classes. Required for delegates and modules.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

static long staticClassID = 0;

class Class
{
public:
	Class()
		: ClassID{staticClassID++}
	{ }
	virtual ~Class() {}


private:

	const long ClassID;
};

