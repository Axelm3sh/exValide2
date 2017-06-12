#include "WorldScene.h"
#include "WorldActor.h"

spWorldScene WorldScene::instance;

WorldScene::WorldScene()
{
	spWorldActor newWorld = new WorldActor;

	newWorld->attachTo(getView());
	//World.setPosition((getView()->getSize().x / 2), (getView()->getSize().y / 2));
	newWorld->InitWorld();
}


WorldScene::~WorldScene()
{
}
