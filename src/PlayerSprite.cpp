#include "PlayerSprite.h"



PlayerSprite::PlayerSprite()
{
	//TODO - image construct
	
}


PlayerSprite::~PlayerSprite()
{

}

void PlayerSprite::doUpdate(const UpdateState & us)
{
	const Uint8* data = SDL_GetKeyboardState(0);

	//calculate speed using delta time
	float speed = 50.0f * (us.dt / 1000.0f);

	Vector2 pos = getPosition();

	if (data[SDL_SCANCODE_A]) pos.x -= speed;
	if (data[SDL_SCANCODE_D]) pos.x += speed;
	if (data[SDL_SCANCODE_W]) pos.y -= speed;
	if (data[SDL_SCANCODE_S]) pos.y += speed;

	spTween posTween = addTween(Actor::TweenPosition(pos)); //TODO
	setPosition(pos);

}
