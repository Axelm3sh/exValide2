#include "WorldActor.h"



WorldActor::WorldActor()
{
}


WorldActor::~WorldActor()
{
}

void WorldActor::InitWorld()
{

	//Simple Initialize 2D Array
	world.resize(HEIGHT);
	for (int i = 0; i < HEIGHT; i++)
	{
		world[i].resize(WIDTH);
	}

	ResAnim* worldsheet = res::ui.getResAnim("TilesAndMasks");

	Vector2 defaultTileSize;
	defaultTileSize.x = 32;
	defaultTileSize.y = 32;

	Vector3 tileOffsets;

	for (int i = 0; i < HEIGHT; i++) 
	{
		for (int j = 0; j < WIDTH; j++)
		{
			tileOffsets.x = this->getX() + defaultTileSize.x*i;
			tileOffsets.y = this->getY() + defaultTileSize.y*j;
			

			world[i][j].Init(worldsheet, Tile::DIRT, defaultTileSize, tileOffsets, this);
		}
	}


}
