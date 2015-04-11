#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
//Engine.hpp is depending on all three previous headers since it references TCODList, Actor and Map.

Engine::Engine() : fovRadius(10),computeFov(true){
	TCODConsole::initRoot(80,50,"Monkey",false);
	player = new Actor(40,25,'@',TCODColor::white);
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
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
	switch(key.vk) {
	case TCODK_UP : 
		if ( ! map->isWall(player->x,player->y-1)) {
			player->y--; 
			computeFov=true;
		}
		break;
	case TCODK_DOWN : 
		if ( ! map->isWall(player->x,player->y+1)) {
			player->y++;
			computeFov=true;
		}
		break;
	case TCODK_LEFT : 
		if ( ! map->isWall(player->x-1,player->y)) {
			player->x--;
			computeFov=true;
		}
		break;
	case TCODK_RIGHT : 
		if ( ! map->isWall(player->x+1,player->y)) {
			player->x++;
			computeFov=true;
		}
		break;
	default:break;
	}
	if(computeFov){
		map->computeFov();
		computeFov=false;
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
