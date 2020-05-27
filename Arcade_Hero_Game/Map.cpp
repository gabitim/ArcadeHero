#include "map.h"

#include <fstream>

Map::Map(const char* mID, int mScale, int tSize) :
	MapID(mID), mapScale(mScale), tileSize(tSize)
{
	scaledSize = mScale * tSize;
}

Map::~Map() {}

void Map::LoadMap(const char* path, int MapSizeX, int MapSizeY)
{
	char c;
	fstream mapCodeFile;
	mapCodeFile.open(path);

	int srcX, srcY;

	for (int y = 0; y < MapSizeY; y++)
	{
		for (int x = 0; x < MapSizeX; x++)
		{
			mapCodeFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapCodeFile.get(c);
			srcX = atoi(&c) * tileSize;
			AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
			mapCodeFile.ignore();

		}
	}

	mapCodeFile.ignore();

	for (int y = 0; y < MapSizeY; y++)
	{
		for (int x = 0; x < MapSizeX; x++)
		{
			mapCodeFile.get(c);
			if (c == '1')
			{
				AddCollision("terrain", x * scaledSize, y * scaledSize, scaledSize);
			}
			mapCodeFile.ignore();
		}

	}

	mapCodeFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	Tile T(srcX, srcY, xpos, ypos, tileSize, mapScale, MapID);
	TilesStorage.emplace_back(T);
}

void Map::AddCollision(string tag, int x_scaledSize, int y_scaledSize, int scaledSize)
{
	Collider col(tag, x_scaledSize, y_scaledSize, scaledSize);
	ColliderStorage.emplace_back(col);
}

void Map::init()
{
	for (vector<Collider>::iterator it = ColliderStorage.begin(); it != ColliderStorage.end(); ++it)
	{
		it->init();
	}
}

void Map::draw()
{
	//cout << TilesStorage.size();
	for (vector<Tile>::iterator it = TilesStorage.begin(); it != TilesStorage.end(); ++it)
	{
		it->draw();
	}

	

}

void Map::update()
{
	for (vector<Tile>::iterator it = TilesStorage.begin(); it != TilesStorage.end(); ++it)
	{
		it->update();
	}


	for (vector<Collider>::iterator it = ColliderStorage.begin(); it != ColliderStorage.end(); ++it)
	{
		it->update();
	}
}


