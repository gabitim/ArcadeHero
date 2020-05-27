#pragma once

#include <iostream>


#include "game.h"
#include "Appearance.h"



class Keyboard : public Component
{
private:
	Evolution* k_evolution = new Evolution;
	Appearance* k_appearance = new Appearance;
public:


	void init() override
	{
		//evolution = fa.components[0];
		k_evolution = dynamic_cast<Evolution*>(components.structComponents[0]);
		k_appearance = dynamic_cast<Appearance*>(components.structComponents[1]);
	}

	void update() override
	{
		//SDL_Event event;
		//SDL_PollEvent(&event);

		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				k_evolution->velocity.second = -1;
				k_appearance->Play("Walk");
				break;

			case SDLK_a:
				k_evolution->velocity.first = -1;
				k_appearance->Play("Walk");
				k_appearance->Flip = SDL_FLIP_HORIZONTAL;
				break;

			case SDLK_d:
				k_evolution->velocity.first = 1;
				k_appearance->Play("Walk");
				break;

			case SDLK_s:
				k_evolution->velocity.second = 1;
				k_appearance->Play("Walk");
				break;
			case SDLK_ESCAPE:

				break;

			default:
				break;
			}
		}

		//SDL_Event event1;
		//SDL_PollEvent(&event1);
		//SDL_PollEvent(&Game::event);

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				k_evolution->velocity.second = 0;
				k_appearance->Play("Idle");
				break;

			case SDLK_a:
				k_evolution->velocity.first = 0;
				k_appearance->Play("Idle");
				k_appearance->Flip = SDL_FLIP_NONE;

				break;

			case SDLK_d:
				k_evolution->velocity.first = 0;
				k_appearance->Play("Idle");
				break;

			case SDLK_s:
				k_evolution->velocity.second = 0;
				k_appearance->Play("Idle");
				break;

			case SDLK_ESCAPE:
				Game::isRunning = false;

			default:
				break;
			}
		}
	}

};