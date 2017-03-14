#include "World.h"

World::World()
{
	
}

World::World(Vector2 size)
{
}

World::~World()
{
	worldRes.free(); //Unloads resources
}