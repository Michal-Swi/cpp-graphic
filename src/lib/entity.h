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
	void set_collision_rectangle(Rectangle &rec) {
		return;
	}

	public:
	virtual
	float get_y() {
		return 0;
	}

	public:
	virtual
	float get_x() {
		return 0;
	}
 
	public:
	virtual
	void update(float &delta_time) {
		return;
	}

	public:
	virtual
	void set_collision_point(Vector2 &collision_point) {
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

