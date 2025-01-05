#include "rectangle.h"
#include <iostream>
#include <raylib.h>

class Ball : public Entity { 
	private:
	float x = 0, y = 0;
	float speed = 700;

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
	void set_collision_rec(const Rectangle &collision_rec) 
		override {
		this->collision_rec = collision_rec;
	}

	public: 
	void update(float &delta_time) override {
		if (collides) {
			y += 10;
		}

		if (forward) {
			x += speed * delta_time;
		} else if (!forward) {
			x -= speed * delta_time;
		}

		if (x <= 0) {
			forward = true; 
		} else if (x >= GetScreenWidth() - rec.width) {
			forward = false;
		}

		rec.x = x;
	}

	public:
	void draw() override {
		DrawRectangle(x, y, rec.width, rec.height, WHITE);
	}
};

