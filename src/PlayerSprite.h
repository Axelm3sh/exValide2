#include "oxygine-framework.h"
#include "SDL.h"
#include "SDL_keyboard.h"

using namespace oxygine;



class PlayerSprite : public Sprite
{
	const int MAX_ANIM_FRAME = 2; //each animation is 2 frames in the sprite sheet.
	const float NEXT_FRAME_TIME = 1;

	enum PClass //Sprite Sheet Row
	{
		KNIGHT = 0,
		PALADIN,
		RANGER,
		NINJA,
		BRAWLER,
		DRAGOON,
		BARD,
		SCHOLAR,
		WHITEMAGE,
		SUMMONER,
		DARKMAGE,
		PUPPETMASTER
	};

	enum PCharState //Sprite Sheet Columns 
	{
		WALKDOWN = 0,
		WALKUP = 2,
		WALKRIGHT = 4,
		WALKLEFT = 6,
		SLEEP = 8,
		LOOKLEFT = 9,
		LOOKRIGHT = 10,
		FAINT = 11,
		PLAYMUSIC = 12,
		WAVERIGHT = 14,
		WAVELEFT = 15,
		PICKUP = 16,
		WAVEDOWN = 18,
		WAVEUP = 20,
		CASTLEFT = 22,
		FALL = 24,
		CASTRIGHT = 25
	};


public:
	PlayerSprite();
	PlayerSprite(PClass character, PCharState state);
	~PlayerSprite();

	PCharState getPlrCardinal();
	void setPlrCardinal(PCharState directionState);

	PCharState getPlayerState();

protected:
	//overloaded doUpdate
	void doUpdate(const UpdateState &us);

	void UpdateSpriteLayer(const UpdateState &us);

private:
	PCharState playerState = WALKDOWN;
	PClass playerClass = KNIGHT;
	Resources localRes;
		
	bool bIsMoving;
	float dtFrameAccumulator;
	int frame;
};

