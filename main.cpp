#include "main.h"

Engine engine(100,80);

int main() {
	engine.load();
    while ( !TCODConsole::isWindowClosed() ) {
    	engine.update();
    	engine.render();
		TCODConsole::flush();    
    }
    engine.save();
    return 0;
}