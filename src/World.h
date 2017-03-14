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
		Vector2 tilePos; //calculated from center offset
		Vector2 tileSize; //Size of tile
		Sprite image;
		TileType type = GROUND;
	};

	typedef std::vector<std::vector<TileData>> WorldGrid;

public:
	World();
	World(Vector2 size); //Overloaded Constructor, define max size
	~World();

protected:

private:
	Resources worldRes; //Image resources to be loaded on creation
	Vector2 worldCenterOffset; //All tiles localized on this point, if this shifts then all tiles shift, maybe for camera?
	Vector2 worldMaxSize; //Max size of world
	
	//bool bIsRandom; //Generate random tiles? (for now, can't read from file so always true)

	WorldGrid world;
};

