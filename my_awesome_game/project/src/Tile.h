#pragma once
#include "oxygine-framework.h"
#include "res.h"
#include "initActor.h"

using namespace oxygine;

class Tile
{
public:
	Tile();
	~Tile();

	enum TileData
	{
		NONE,
		DIRT,
		GRASS,
		ROCK,
		WATER_WALK,
		WATER_SWIM,
		AIR,
		FIRE
		//TODO - More tile data if needed?
	};

	void Init(const AnimationFrame& image, TileData tileType, Vector2 size, Vector2 position, spActor attach);


protected:

	spMaskedSprite tileImage;
	TileData tileData;
	Vector2 tileSize; //xy scale?
	Vector2 tilePosition; //X, Y
	spActor attachTo;

};

