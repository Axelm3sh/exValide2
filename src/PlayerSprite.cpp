#include "PlayerSprite.h"



PlayerSprite::PlayerSprite()
{
	setPlrCardinal(WALKDOWN); //Default spawn Cardinal
	bIsMoving = false;
	frame = 0;
	dtFrameAccumulator = 0;

	localRes.loadXML("res.xml");

	//Default sprite
	setResAnim(localRes.getResAnim("Players_SpriteSheet"), playerState, playerClass);
}

PlayerSprite::PlayerSprite(PClass character, PCharState state)
{
	//setPlrCardinal(WALKDOWN); //Default spawn Cardinal
	bIsMoving = false;
	frame = 0;
	dtFrameAccumulator = 0;

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
	//Todo: return only cardinal directions
	return playerState;
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

	bIsMoving = false; //If we didn't press any keys, this stays false.

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

void PlayerSprite::UpdateSpriteLayer(const UpdateState us)
{
	dtFrameAccumulator += (us.dt / 1000.0f); //count delta time
	std::string time = std::to_string(dtFrameAccumulator);
	log::messageln(time.c_str());

	if (bIsMoving) //if player is moving, do the update for frames
	{
		if (dtFrameAccumulator >= 0.5f)
		{
			frame++; //increment frame number
			if (frame > 1)
			{
				frame = 0;
			}
			dtFrameAccumulator = 0.0f; //Reset frame accumulator
		}
	}
	else //else, we stand still
	{
		frame = 0;
	}
	
	//getPlayerState()
	//TODO Check keystates, update accordingly
	setResAnim(localRes.getResAnim("Players_SpriteSheet"), playerState + frame, playerClass);

}
