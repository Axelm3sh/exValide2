#include "WorldActor.h"



WorldActor::WorldActor()
{
}


WorldActor::~WorldActor()
{
	Cleanup();

	this->detach();
}

void WorldActor::InitWorld()
{

	//TODO DEBUG backgroundcolor
	spColorRectSprite bgColor = new ColorRectSprite;
	bgColor->setColor(Color::DarkOrchid);
	bgColor->setSize(getParent()->getSize());
	bgColor->attachTo(this);

	//Simple Initialize 2D Array
	world.resize(HEIGHT);
	for (int i = 0; i < HEIGHT; i++)
	{
		world[i].resize(WIDTH);
	}

	ResAnim* worldsheet = res::worldSpr.getResAnim("TilesAndMasks");
	if (!worldsheet)
	{
		worldsheet = res::worldSpr.getResAnim("BG_Tiles_And_Masks");
		if (!worldsheet)
		{
			log::error("Error: could not find Tile images");
			return;
		}
	}
	else
	{
		log::messageln("Tiles loaded!");
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
			
			//DEBUG random tile TODO
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
		while(!world.back().empty())
		{ 
			world.back().pop_back();
		}
		world.pop_back();
	}


	std::string msg = std::to_string(world.size());

	log::messageln(msg.c_str());

}
