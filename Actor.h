class Actor {
public :
	int x,y; //position on the map
	int ch; // ascii code
	TCODColor col; // the colour

	Actor(int x, int y, int ch, const TCODColor &col);
	void render() const;
};

// added as an int so you can have 256 different characters
