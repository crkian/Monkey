class Container {
public :
	int size; // max number, infinate- 0
	TCODList<Actor *> inventory;

	Container(int size);
	~Container();
	bool add(Actor *actor);
	void remove(Actor *actor);
};