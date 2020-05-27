#include "game.h"
#include "map.h"

#include"Entity.h"
#include "Collision.h"


SDL_Renderer* Game::renderer = nullptr;
Map* map1;
Entity* player;


bool Game::isRunning = false;
SDL_Event Game::event;

SDL_Rect Game::camera = { 0,0, 800, 640 };

Game::Game() {}

Game::~Game() {}
                                               
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flag_Full_Screen = 0;

	if (fullscreen)
	{
		flag_Full_Screen = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag_Full_Screen);
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);
			cout << "Renderer created! \n";
		}

		isRunning = true;
	}

	map1 = new Map("assets/terrain_ss.png", 2, 32);
	map1->LoadMap("assets/map.map", 25, 20);

	player = new Entity( "assets/player_anims.png");
	player->init();

	map1->init();

	SDL_RenderPresent(renderer);

}

void Game::handleEvents()
{
	
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		
		default:
			break;
		}
	}

}

void Game::update()
{
	pair<int, int> playerPosition;
	playerPosition = player->getPositionEvolution();

	SDL_Rect playerCol = player->getCollider();

	map1->update();
	player->update();

	for (vector<Collider>::iterator it = map1->ColliderStorage.begin(); it != map1->ColliderStorage.end(); ++it)
	{
		SDL_Rect cCol = it->collider;
		if (Collision::AABB(cCol, playerCol))
		{
			cout << " colision ";
			player->setPositionEvolution(playerPosition);
		}
	}

	camera.x = playerPosition.first - 400;
	camera.y = playerPosition.second - 320;

	if (camera.x < 0)
		camera.x = 0;

	/*if (camera.x > 468)
		camera.x = 468;*/

	if (camera.y < 0)
		camera.y = 0;

	if (camera.x > camera.w)
		camera.x = camera.w;

	if (camera.y > camera.h)
		camera.y = camera.h;

	
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map1->draw();
	player->draw();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	delete[] player->components.structComponents;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}