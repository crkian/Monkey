struct Tile {
	bool explored; //tile is walkable
	Tile() :explored(false)
	{}
};

class Map {
public :
	int width,height;

	Map(int width,int height);
	~Map();
	bool isWall(int x, int y) const;
	bool isInFov(int x, int y)const;
	bool isExplored(int x, int y)const;
	bool canWalk(int x, int y) const;
	void computeFov();
	void render() const;
protected :
	Tile *tiles;
	TCODMap *map;
	friend class BspListener;
	//We replace the setWall function by a function that digs a rectangular zone. We also make a declaration that will allow some BspListener class to use the protected dig function. The BspListener class is not declared in the header because it's private to the Map class. The createRoom function will dig the room and populate it with actors.
	void dig(int x1, int y1, int x2, int y2);
	void createRoom(bool first, int x1, int y1, int x2, int y2);
	void addMonster(int x, int y);
};