class Engine {
public :
	TCODList<Actor *> actors; //actors is all on map, actor has seperate pointer for walking
	Actor *player;
	Map *map;

	Engine();
	~Engine();
	void update();
	void render();
};

extern Engine engine; //The extern declaration tells the compiler that somewhere, in a .cpp file, there is a global variable named engine