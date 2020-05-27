#pragma once

#include "game.h"
#include "TileCreation.h"
#include "Collider.h"

#include <string>
#include <vector>


class Map : public Tile
{
private:
	const char* MapID;
	int mapScale;
	int tileSize;
	int scaledSize;

public:
	Map(const char* MapID, int MapScale, int tileSize);
	~Map();

	void LoadMap(const char* path, int MapSizeX, int MapSizeY);
	void AddTile(int srcX, int srcY, int xpos, int ypos);
	void AddCollision(string, int, int, int);
	
	void init();
	void draw();
	void update();
	
	vector <Tile> TilesStorage; 
	vector <Collider> ColliderStorage;

};