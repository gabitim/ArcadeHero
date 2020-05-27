#pragma once

#include <iostream>

#include "game.h"
#include "Evolution.h"
#include "Texture.h"

class Collider : public Component
{
public:
	SDL_Rect collider;
	string tag;

	SDL_Texture* tex;
	SDL_Rect srcR, destR;

	Evolution* evolution;

	Collider(string tag)
	{
		//cout << "1";
		this->tag = tag;
	}

	Collider(string tag, int xpos, int ypos, int size)
	{
		static int i= 0;
		//cout << i<<" ";
		i++;
		this->tag = tag;
		collider.x = xpos;
		collider.y = ypos;
		collider.h = collider.w = size;
	}

	void init() override
	{
		if (components.structComponents[0] == nullptr)
		{
			evolution = new Evolution;
			components.structComponents[0] = evolution;
		}

		evolution = dynamic_cast<Evolution*>(components.structComponents[0]);

		tex = Texture::LoadTexture("assets/ColTex.png");
		srcR = { 0,0,32,32 };
		destR = { collider.x, collider.y, collider.w, collider.h };
	}

	void update() override
	{
		if (tag != "terrain")
		{
			//cout << "aa";
			collider.x = static_cast<int> (evolution->position.first);
			collider.y = static_cast<int> (evolution->position.second);
			collider.w = evolution->width * evolution->scale;
			collider.h = evolution->height * evolution->scale;
		}

		destR.x = collider.x - Game::camera.x;
		destR.y = collider.y - Game::camera.y;
	}

	void draw() override
	{
		Texture::Draw(tex, srcR, destR, SDL_FLIP_NONE);
	}

	SDL_Rect getCollider()
	{
		return collider;
	}
};