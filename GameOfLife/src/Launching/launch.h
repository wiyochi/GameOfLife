#pragma once
#include "../Window/Window.h"
#include "../Cell/CellArray.h"
#include <thread>
#include <chrono>

void launchWindow(int width, int height);
void waitEvent(Window* window, SDL_Renderer* renderer, CellArray* cellTab);