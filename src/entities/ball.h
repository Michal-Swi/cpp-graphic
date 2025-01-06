#include "rectangle.h"
#include <iostream>
#include <raylib.h>

class Ball : public Entity { 
	private:
	float x = 400, y = 0;
	float speed = 700;

	public:
	float get_x() override {
		return x;
	}
	
	public:
	float get_y() override {
		return y;
	}

	private:
	Texture2D texture;
	Rectangle rec;

	public: 
	Rectangle get_rec() override {
		return rec;
	}

	public:
	void load(Texture2D &texture) override {
		this->texture = texture;

		rec = {
			x, y,
			float(texture.width),
			float(texture.height)
		};
	}
	
	private:
	bool forward = true;
	bool collides = false;
	Rectangle collision_rec;

	public:
	void set_collides(const bool &collides) override {
		this->collides = collides;
	}

	public: 
	void update(float &delta_time) override {
		if (collides) {
			forward = !forward;
		}

		if (forward) {
			x += speed * delta_time;
		} else if (!forward) {
			x -= speed * delta_time;
		}
	}

	public:
	void draw() override {
		DrawTextureRec(texture, rec, {x, y}, WHITE);
	}
};

