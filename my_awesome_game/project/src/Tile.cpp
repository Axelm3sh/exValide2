#include "Tile.h"



Tile::Tile()
{
	//tileImage = NULL;
	tileData = NONE;
	tileSize.setZero(); //xy scale?
	tilePosition.setZero(); //X, Y pos
}


Tile::~Tile()
{
	//Detatch sprite from parent, calls internal clean up
	tileImage->detach();
}

void Tile::Init(AnimationFrame image, TileData tileType, Vector2 size, Vector2 position, spActor attach)
{

	tileSize = size;
	tilePosition = position;

	tileImage = initActor(new Sprite, arg_animFrame = image, arg_position = tilePosition, arg_attachTo = attach);
	tileData = tileType;


}
