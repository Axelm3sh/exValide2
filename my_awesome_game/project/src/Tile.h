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

	void Init(ResAnim* image, TileData tileType, Vector2 size, Vector3 position, spActor attach);


protected:

	spSprite tileImage;
	TileData tileData;
	Vector2 tileSize; //xy scale?
	Vector3 tilePosition = 0; //X, Y, Z = depth for overlap/masks/decals?
	spActor attachTo;

};

