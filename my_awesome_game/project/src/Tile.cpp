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
	tileImageBottom->detach();

}

void Tile::Init(const AnimationFrame& image, TileData tileType, Vector2 size, Vector2 position, spActor attach)
{

	tileSize = size;
	tilePosition = position;

	tileImageBottom = initActor(new MaskedSprite, arg_resAnim = image, arg_position = tilePosition, arg_attachTo = attach);
	tileData = tileType;

	//ResAnim* mask = res::ui.getResAnim("TilesAndMasks");
	//spSprite maskFrame = new Sprite;

	//int min = 13;

	////maskFrame->setAnimFrame(mask, rand() % mask->getColumns(), min + (rand() % static_cast<int>(mask->getRows() - min)));
	//maskFrame->setAnimFrame(mask, rand() % mask->getColumns(), (rand() % mask->getRows()) );
	//tileImage->setMask(maskFrame, false);
}
