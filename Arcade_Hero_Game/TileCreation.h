#pragma once

#include "SDL.h"
#include "game.h"
#include "Texture.h"

using namespace std;

class Tile
{
public:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	pair <int, int> position;

	Tile() = default;

	~Tile()
	{
		//problem 
		//it destroys everytime
		
		//SDL_DestroyTexture(texture);

		//got to work on this
		//when we change textures!!
	}

	Tile(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, const char* id)
	{

		texture = Texture::LoadTexture(id);

		position.first = xpos;
		position.second = ypos;

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = tsize;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = tsize * tscale;
			
	}

	void update()
	{
		destRect.x = position.first - Game::camera.x;
		destRect.y = position.second - Game::camera.y;

	}

	void draw()
	{
		Texture::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};