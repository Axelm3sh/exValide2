#include "CustomScene.h"

CustomScene::CustomScene()
{
    _view = new Actor;
    _view->setSize(getStage()->getSize());
	_holder->addChild(_view);
}