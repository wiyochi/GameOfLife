#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "launch.h"

std::string firstInput();
void golInput();
void selectInput(std::string golIn, int width, int height);
void windowInput(std::string str, int* w, int* h);
int speedInput();
int argInt(std::string str, int i, int* adI);