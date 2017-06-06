#pragma once
#include "oxygine-framework.h"
#include <vector>
#include "Tile.h"

using namespace oxygine;

const int HEIGHT = 10;
const int WIDTH = 15;

class WorldActor : public Actor
{
public:
	WorldActor();
	~WorldActor();

	void InitWorld();

	void Cleanup();


protected:

	//Empty actor to attach tiles to, positions will be calculated via offsets
	//spActor anchorPointOrigin; 

	//World Matrix
	typedef std::vector<std::vector<Tile>> worldMatrix;
	worldMatrix world;

};

