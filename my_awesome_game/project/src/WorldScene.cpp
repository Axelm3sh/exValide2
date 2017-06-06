#include "WorldScene.h"
#include "WorldActor.h"

spWorldScene WorldScene::instance;

WorldScene::WorldScene()
{
	World.attachTo(getView());
	//World.setPosition((getView()->getSize().x / 2), (getView()->getSize().y / 2));
	World.InitWorld();
}


WorldScene::~WorldScene()
{
}
