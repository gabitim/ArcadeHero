#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Texture.h"
#include "Evolution.h"
#include"Component.h"

using namespace std;

struct assets
{
	std::map<string, SDL_Texture*> textures;
};

struct Animation
{

	int index;
	int frames;
	int speed;

	Animation() {}
	Animation(int i, int f, int s)
	{
		index = i;
		frames = f;
		speed = s;
	}
};

class Appearance : public Component
{
private:

	assets aset;


	Evolution* evolution = nullptr;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;
	
	int scale = 2;

public:
	int animIndex = 0;
	std::map<const char*, Animation> animations;

	SDL_RendererFlip Flip = SDL_FLIP_NONE;

	Appearance() = default;
	Appearance(const char* id)
	{
		setTex(id);
	}

	Appearance(const char* path, bool isAnimated)
	{
		animated = isAnimated;

		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		Play("Idle");
		setTex(path);
	}

	~Appearance()
	{}

	void init() override
	{
		evolution = dynamic_cast<Evolution*>(components.structComponents[0]);
		

		srcRect.x = srcRect.y = 0;
		
		srcRect.w = evolution->width;
		srcRect.h = evolution->height;

		destRect.x = evolution->position.first;
		destRect.y = evolution->position.second;

		destRect.w = destRect.h = 64;
	}

	void update() override
	{

		

		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
			//cout << srcRect.x << "\n";
		}

		srcRect.y = animIndex * evolution->height;

		destRect.x = evolution->position.first - Game::camera.x;
		destRect.y = evolution->position.second - Game::camera.y;

		destRect.w = evolution->width * evolution->scale;
		destRect.h = evolution->height * evolution->scale;
	}

	void draw() override
	{
		Texture::Draw(texture, srcRect, destRect, Flip);
	}

	void setTex(const char* id)
	{
		//texture = aset.textures[id];

		texture = Texture::LoadTexture(id);
	}

	void Play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}

	
};