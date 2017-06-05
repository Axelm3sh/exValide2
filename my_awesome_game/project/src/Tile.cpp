#include "Tile.h"



Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::Init(ResAnim* image, TileData tileType, Vector2 size, Vector3 position, spActor attach)
{
	const AnimationFrame& frame = image->getFrame(rand() % image->getColumns(), rand() % image->getRows());

	tileImage = initActor(new Sprite, arg_resAnim = frame, arg_anchor = Vector2(position.x, position.y), arg_attachTo = attach);
	tileData = tileType;


}
