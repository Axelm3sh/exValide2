#include "res.h"
#include "oxygine-sound.h"
#include <map>
extern  SoundPlayer player;

namespace res
{
    Resources ui;
	Resources playerSpr;
	Resources worldSpr;
	typedef std::map<string, ResSound*> Sounds;
	Sounds sounds;

    void load()
    {
        ui.loadXML("xmls/UIRes.xml");
		ui.print(); //DEBUG

		playerSpr.loadXML("xmls/PlayerSprRes.xml");
		playerSpr.print(); //DEBUG

		worldSpr.loadXML("xmls/WorldSprRes.xml");
		worldSpr.print(); //DEBUG

        sounds["click"] = ResSound::create("sounds/button_click.ogg", false);
		sounds["bomb_match"] = ResSound::create("sounds/bomb_match.ogg", false);
    }

    void free()
    {
        player.stop();
        ui.free();
		playerSpr.free();
		worldSpr.free();

		for (Sounds::iterator i = sounds.begin(); i != sounds.end(); ++i)
		{
			delete i->second;
		}
    }
}


void playSound(const string& id)
{
    player.play(res::sounds[id]);
}