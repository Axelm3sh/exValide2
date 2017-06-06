#include "WorldScene.h"
#include "WorldActor.h"

spWorldScene WorldScene::instance;

WorldScene::WorldScene()
{
	World.attachTo(getView());
	World.InitWorld();
}


WorldScene::~WorldScene()
{
}
