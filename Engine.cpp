#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
//Engine.hpp is depending on all three previous headers since it references TCODList, Actor and Map.

Engine::Engine() : gameStatus(STARTUP), fovRadius(10) {
	TCODConsole::initRoot(80,50,"Monkey",false);
	player = new Actor(40,25,'@',"player",TCODColor::white);
	actors.push(player);
	map = new Map(80,45);
}
// allocate two Actor objects, one for the player and one for some NPC, and store the object adresses in the actors list. The Map object is also dynamically allocated.


Engine::~Engine() {
	actors.clearAndDelete();
	delete map;
}


//is wall is collision detection
void Engine::update() {
    TCOD_key_t key;
    if ( gameStatus == STARTUP ) map->computeFov();
    gameStatus=IDLE;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
    int dx=0,dy=0;
    switch(key.vk) {
		case TCODK_UP : dy=-1; break;
		case TCODK_DOWN : dy=1; break;
		case TCODK_LEFT : dx=-1; break;
		case TCODK_RIGHT : dx=1; break;
        default:break;
    }
    if ( dx != 0 || dy != 0 ) {
    	gameStatus=NEW_TURN;
    	if ( player->moveOrAttack(player->x+dx,player->y+dy) ) {
	    	map->computeFov();
	    }
	}
	if ( gameStatus == NEW_TURN ) {
	    for (Actor **iterator=actors.begin(); iterator != actors.end();
	        iterator++) {
	        Actor *actor=*iterator;
	        if ( actor != player ) {
	            actor->update();
	        }
	    }
	}
}

void Engine::render() {
	TCODConsole::root->clear();
	// draw the map
	map->render();
	// draw the actors
	for (Actor **iterator=actors.begin(); 
		iterator != actors.end(); iterator++) {
			Actor *actor=*iterator;
			if ( map->isInFov(actor->x,actor->y) ) {
				actor->render();
			}
	}
}
//The TCODList begin() function returns a pointer to the first element. Since our elements are already Actor pointers, we get a pointer to a pointer to an Actor : Actor **. We use the indirection operator (*iterator) to retrieve the object behind the pointer (the actual Actor pointer) and the dereference operator -> to access a member on the pointed object (the actual Actor). 
