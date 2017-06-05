#include "oxygine-framework.h"
#include "oxygine-sound.h"
#include "res.h"
//#include "Game.h"
//#include "MainMenuScene.h"
//#include "GameScene.h"
//#include "GameMenu.h"
#include "WorldScene.h"
#include "ResFontFT.h"
using namespace oxygine;


SoundPlayer player;

void example_preinit()
{
}

void example_init()
{
	ResFontFT::initLibrary();
    ResFontFT::setSnapSize(10);

    SoundSystem::create()->init(4);
    
    //load resources
    res::load();

	flow::init();
    //create all scenes/stages 
    /*GameMenu::instance = new GameMenu;
    GameScene::instance = new GameScene;
    MainMenuScene::instance = new MainMenuScene;*/
	WorldScene::instance = new WorldScene;

    //show main menu
    //flow::show(MainMenuScene::instance);

	flow::show(WorldScene::instance);

}

void example_update()
{
    SoundSystem::get()->update();
    player.update();
	flow::update();
}

void example_destroy()
{
    /*MainMenuScene::instance = 0;
    GameScene::instance = 0;
    GameMenu::instance = 0;*/

	WorldScene::instance = 0;

    res::free();
	ResFontFT::freeLibrary();

    SoundSystem::free();
	flow::free();
}