#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "SDL.h"
#include "Window/Window.h"
#include "Cell/Cell.h"
#include "Cell/CellArray.h"
#include "Launching\launch.h"
#include "Launching\input.h"
#undef main

int main(int argc, char** argv)
{
	golInput();

	system("PAUSE");
	return 0;
}