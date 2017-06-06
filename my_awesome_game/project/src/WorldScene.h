#include "CustomScene.h"
#include "WorldActor.h"

using namespace oxygine;

DECLARE_SMART(WorldScene, spWorldScene);
class WorldScene : public CustomScene
{
public:
	static spWorldScene instance;

	WorldScene();
	~WorldScene();

private:
	void onEvent(Event* ev);

	WorldActor World;
};

