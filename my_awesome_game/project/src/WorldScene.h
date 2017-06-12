#include "CustomScene.h"
#include "WorldActor.h"

using namespace oxygine;

DECLARE_SMART(WorldScene, spWorldScene);
DECLARE_SMART(WorldActor, spWorldActor);
class WorldScene : public CustomScene
{
public:
	static spWorldScene instance;

	WorldScene();
	~WorldScene();

private:
	void onEvent(Event* ev);

	spWorldActor World;
};

