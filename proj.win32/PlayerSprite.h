#include "oxygine-framework.h"
#include "SDL.h"
#include "SDL_keyboard.h"

using namespace oxygine;

class PlayerSprite : public Sprite
{
public:
	PlayerSprite();
	~PlayerSprite();

protected:
	//overloaded doUpdate
	void doUpdate(const UpdateState &us);
};

