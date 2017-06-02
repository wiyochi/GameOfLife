#pragma once
#include "../Window/Window.h"
#include "../Cell/CellArray.h"
#include <thread>
#include <chrono>

void launchWindow(Window* mainWindow, SDL_Renderer* renderer, CellArray* cellTab);
void waitEvent(Window* window, SDL_Renderer* renderer, CellArray* cellTab);