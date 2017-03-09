#include "World.h"

World::World()
{

}

World::~World()
{
	worldRes.free(); //Unloads resources
}