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

void Tile::Init(const AnimationFrame& image, TileData tileType, Vector2 size, Vector2 position, spActor attach)
{

	tileSize = size;
	tilePosition = position;

	tileImage = initActor(new MaskedSprite, arg_resAnim = image, arg_position = tilePosition, arg_attachTo = attach);
	tileData = tileType;

	//tileImage->setMask();
}
