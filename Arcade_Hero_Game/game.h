#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

using namespace std;


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();
	
	SDL_Window* window;

	static SDL_Renderer* renderer;
	static SDL_Event event;

	static SDL_Rect camera;

	static bool isRunning;

};