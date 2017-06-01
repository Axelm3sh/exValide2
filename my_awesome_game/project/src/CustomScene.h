#pragma once
#include "oxygine-framework.h"
#include "oxygine-flow.h"

#include <vector>
using namespace oxygine;
using namespace std;

/*
	Container-like actor which can dictate what shows up on the screen.
	Think of a Stage play where every time the curtain rises, there will be new props and actors
	within this scene.

	Use with Oxygine-Flow to transition from scene to scene
*/

DECLARE_SMART(Scene, spScene);
class CustomScene: public flow::Scene
{
public:
    CustomScene();

    spActor getView() const {return _view;}

protected:
    spActor _view;
};



