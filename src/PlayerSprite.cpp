#include "PlayerSprite.h"



PlayerSprite::PlayerSprite()
{
	setPlrCardinal(WALKDOWN); //Default spawn Cardinal
	bIsMoving = false;
	frame = 0;

	localRes.loadXML("res.xml");

	//Default sprite
	setResAnim(localRes.getResAnim("Players_SpriteSheet"), playerState, playerClass);
}

PlayerSprite::PlayerSprite(PClass character, PCharState state)
{
	//setPlrCardinal(WALKDOWN); //Default spawn Cardinal
	bIsMoving = false;
	frame = 0;

	localRes.loadXML("res.xml");

	//Default sprite
	setResAnim(localRes.getResAnim("Players_SpriteSheet"), state, character);
}


PlayerSprite::~PlayerSprite()
{
	localRes.free(); //frees res
}

//Return current Cardinal Direction
PlayerSprite::PCharState PlayerSprite::getPlrCardinal()
{
	return ;
}

void PlayerSprite::setPlrCardinal(PCharState dir)
{
	if (playerState != dir)
	{
		playerState = dir;
	}
	
	//Update sprite to fit direction
}

PlayerSprite::PCharState PlayerSprite::getPlayerState()
{
	return playerState;
}

void PlayerSprite::doUpdate(const UpdateState & us)
{
	const Uint8* data = SDL_GetKeyboardState(0);

	//calculate speed using delta time
	float speed = 50.0f * (us.dt / 1000.0f);

	Vector2 pos = getPosition();

	if (data[SDL_SCANCODE_A])
	{
		pos.x -= speed;
		setPlrCardinal(WALKLEFT);
		bIsMoving = true;
		log::message("LEFT");
	}
	if (data[SDL_SCANCODE_D])
	{
		pos.x += speed;
		setPlrCardinal(WALKRIGHT);
		bIsMoving = true;
		log::message("RIGHT");
	}
	if (data[SDL_SCANCODE_W]) 
	{
		pos.y -= speed;
		setPlrCardinal(WALKUP);
		bIsMoving = true;
		log::message("UP");
	}
	if (data[SDL_SCANCODE_S])
	{
		pos.y += speed;
		setPlrCardinal(WALKDOWN);
		bIsMoving = true;
		log::message("DOWN");
	}

	//TODO: Check keys for nothing pressed
	UpdateSpriteLayer(us);
	setPosition(pos);

}

void PlayerSprite::UpdateSpriteLayer(const UpdateState & us)
{
	dtFrameAccumulator += us.dt; //count delta time

	if (dtFrameAccumulator >= 1.0f)
	{
		frame++; //increment frame number
		if (frame > 1)
		{
			frame = 0;
		}
		dtFrameAccumulator = 0.0f; //Reset frame accumulator
	}
	
	//getPlayerState()
	//TODO Check keystates, update accordingly
	setResAnim(localRes.getResAnim("Players_SpriteSheet"), playerState + frame, playerClass);

}
