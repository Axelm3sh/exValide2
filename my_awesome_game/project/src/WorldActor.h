#pragma once
#include "oxygine-framework.h"
#include <vector>
#include "Tile.h"

using namespace oxygine;

const int HEIGHT = 5;
const int WIDTH = 5;

class WorldActor : public Actor
{
public:
	WorldActor();
	~WorldActor();

	void InitWorld();


protected:

	//Empty actor to attach tiles to, positions will be calculated via offsets
	//spActor anchorPointOrigin; 

	//World Matrix
	typedef std::vector<std::vector<Tile>> worldMatrix;
	worldMatrix world;

};

