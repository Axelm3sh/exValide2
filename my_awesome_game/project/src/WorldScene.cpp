#include "WorldScene.h"
#include "WorldActor.h"


WorldScene::WorldScene()
{
	World.attachTo(getView());
	World.InitWorld();
}


WorldScene::~WorldScene()
{
}
