#include "AppMain.h"

#undef main

int main(int argc, char** argv[])
{
	AppMain app;
	app.Init();
	app.Loop();

	return 0;
}