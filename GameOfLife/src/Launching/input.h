#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "launch.h"

std::string firstInput();
void golInput();
void waitEventMainThread(std::string golIn, int width, int height);
void selectInput(CellArray* cellTab);
int argInt(std::string str, int i, int* adI);
void help();