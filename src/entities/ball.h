#include "point.h"
#include <iostream>
#include <raylib.h>

enum VeritcalDirection {
	up,
	down,
	straight
};

class Ball : public Entity { 
	private:
	float x = 400, y = 0;
	float speed = 800;

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

	private:
	Points points;

	public:
	void load_points(Player *&player1, Player *&player2) {
		points.set_players(player1, player2);
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
	VeritcalDirection veritcal_direction = up;	
	bool collides = false;
	Vector2 collision_point;

	public:
	void set_collision_point(Vector2 &collision_point) 
		override {
		this->collision_point = collision_point;
	}

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
		
		switch (veritcal_direction) {
			case up:
				y += 10;
				break;
			case down:
				y -= 10;
				break;
			case straight:
				break;
		}

		if (y < 0) {
			y = 1;
			veritcal_direction = up;
		} else if (y + rec.height >= GetScreenHeight()) {
			y = GetScreenHeight() - rec.height;
			veritcal_direction = down;
		}

		if (x > 0 and x < GetScreenWidth()) {
			return;
		}
		
		int half_width = GetScreenWidth() / 2;

		if (x < half_width) {
			points.add_point(2);
		}

		if (x > half_width) {
			points.add_point(1);
		}

		x = half_width;
	}

	public:
	void draw() override {
		DrawTextureRec(texture, rec, {x, y}, WHITE);
	}
};

