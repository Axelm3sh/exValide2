#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;

void example_preinit() {}

spSprite image;

//After animations done, check sprite pos
void tweenDoneHandle(Event* e)
{
	if (image->getY() < 0)
	{
		image->addTween(Actor::TweenY(getStage()->getSize().y / 2), 100, 1);
	}
}
//Gets called on clicks
void onClickFunction(Event* e)
{
	log::message("Clicked the sprite!");

	float distToMove = -100.f; //units
	int timeToMove = 400; //ms

	//Tween Y dist, add smooth translation
	spTween tweenPos = image->addTween(Actor::TweenY(image->getY() + distToMove), timeToMove);
	//Tween Scale
	spTween tweenScale = image->addTween(Actor::TweenScaleY(image->getScaleY() + 0.7), 200, 1, true);

	//Event done Handler
	tweenPos->addDoneCallback(tweenDoneHandle);


}


//called from main.cpp
void example_init()
{
    //load xml file with resources definition
    gameResources.loadXML("res.xml");

	image = new Sprite;
	//Init sprite, note-- 0 base array
	image->setResAnim(gameResources.getResAnim("Players_SpriteSheet"), 16, 11);
	image->attachTo(getStage());
	image->setPosition(getStage()->getSize() / 2); //Center on screen

	//add an event listener and listen to Clicks
	image->addClickListener(onClickFunction);

}


//called each frame from main.cpp
void example_update()
{
}

//called each frame from main.cpp
void example_destroy()
{
    //free previously loaded resources
    gameResources.free();
}
