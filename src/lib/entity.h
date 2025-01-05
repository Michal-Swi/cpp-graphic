#include <raylib.h>

class Entity {
	public:
	Rectangle rec;
	
	public:
	virtual
	Rectangle get_rec() {
		return rec;
	}
	
	public:
	virtual
	void set_collides(const bool &collides) {
		return;
	}

	public:
	virtual
	void set_collision_rec(const Rectangle &collision_rec) {
		return;
	}
 
	public:
	virtual
	void update(float &delta_time) {
		return;
	}

	public:
	virtual 
	void load(Texture2D &texture) {
		return;
	}

	public:
	virtual 
	void draw() {
		return;
	}
};

