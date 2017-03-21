#include "PlayerSprite.h"



PlayerSprite::PlayerSprite()
{
	setPlrCardinal(DOWN);
	//TODO - image construct
	localRes.loadXML("res.xml");
	spriteCol = 17;
	spriteRow = 0;
	setResAnim(localRes.getResAnim("Players_SpriteSheet"), spriteCol, spriteRow);
}


PlayerSprite::~PlayerSprite()
{
	localRes.free(); //frees res
}

//Return current Cardinal Direction
PlayerSprite::Cardinal PlayerSprite::getPlrCardinal()
{
	return plrDirection;
}

void PlayerSprite::setPlrCardinal(Cardinal dir)
{
	if (plrDirection != dir)
	{
		plrDirection = dir;
	}
	
	//Update sprite to fit direction
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
		setPlrCardinal(LEFT);
		log::message("LEFT");
	}
	if (data[SDL_SCANCODE_D])
	{
		pos.x += speed;
		setPlrCardinal(RIGHT);
		log::message("RIGHT");
	}
	if (data[SDL_SCANCODE_W]) 
	{
		pos.y -= speed;
		setPlrCardinal(UP);
		log::message("UP");
	}
	if (data[SDL_SCANCODE_S])
	{
		pos.y += speed;
		setPlrCardinal(DOWN);
		log::message("DOWN");
	}

	setPosition(pos);

}
