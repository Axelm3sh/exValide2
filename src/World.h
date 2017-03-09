#include "oxygine-framework.h"

using namespace oxygine;



class World
{
	enum TileType
	{
		GROUND = 0,
		WATER,
		WALL
	};

	struct TileData
	{
		Vector2 tilePos;
		Vector2 tileSize;
		Sprite image;
		TileType type;
	};

public:
	World();
	~World();

protected:

private:
	Resources worldRes; //Image resources to be loaded on creation
	Vector2 worldCenterOffset; //All tiles localized on this point, if this shifts then all tiles shift
	Vector2 worldMaxSize; //Max size of world
	
	//bool bIsRandom; //Generate random tiles? (for now, can't read from file so always true)

};

