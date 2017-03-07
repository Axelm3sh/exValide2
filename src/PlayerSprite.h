#include "oxygine-framework.h"
#include "SDL.h"
#include "SDL_keyboard.h"

using namespace oxygine;



class PlayerSprite : public Sprite
{
	enum Cardinal
	{
		DOWN = 0,
		UP,
		RIGHT,
		LEFT
	};

public:
	PlayerSprite();
	~PlayerSprite();

	Cardinal getPlrCardinal();
	void setPlrCardinal(Cardinal dir);

protected:
	//overloaded doUpdate
	void doUpdate(const UpdateState &us);

private:
	Cardinal plrDirection;
	Resources localRes;
};

