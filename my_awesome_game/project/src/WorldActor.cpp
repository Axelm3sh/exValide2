#include "WorldActor.h"



WorldActor::WorldActor()
{
}


WorldActor::~WorldActor()
{
	Cleanup();
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
	if (!worldsheet)
	{
		worldsheet = res::ui.getResAnim("BG_Tiles_And_Masks");
		if (!worldsheet)
		{
			log::error("Error: could not find Tile images");
		}
	
	}

	Vector2 defaultTileSize;
	defaultTileSize.set(64.f,64.f);

	Vector2 tileOffsets;
	tileOffsets.setZero();

	for (int i = 0; i < HEIGHT; i++) 
	{
		for (int j = 0; j < WIDTH; j++)
		{
			//Calculate offsets per tile for all tiles
			tileOffsets.x = this->getX() + (defaultTileSize.x * i);
			tileOffsets.y = this->getY() + (defaultTileSize.y * j);
			
			//DEBUG random tile
			const AnimationFrame& frame = worldsheet->getFrame(rand() % worldsheet->getColumns(), rand() % worldsheet->getRows());

			//Set tile data
			world[i][j].Init(frame, Tile::DIRT, defaultTileSize, tileOffsets, this);
		}
	}


}

void WorldActor::Cleanup()
{
	//TODO get rid of world in a clean way lol
	while (!world.empty())
	{
		while(!world.begin()->empty)
		{ 
			world.begin()->pop_back();
		}
		world.pop_back();
	}
}
