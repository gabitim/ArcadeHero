#pragma once

#include <iostream>

#include "Appearance.h"
#include "Keyboard.h"
#include "Collider.h"

using namespace std;

class Entity : public Component
{

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
public:

	Appearance* appearance = nullptr;
	Evolution* evolution = nullptr;
	Keyboard* keybourd = nullptr;
	Collider* collider = nullptr;


	Entity() = default;
	Entity(const char* path);

	void init();

	void update();

	void draw();

	pair<int, int > getPositionEvolution();
	void setPositionEvolution(pair<int,int>);
	SDL_Rect getCollider();

};
