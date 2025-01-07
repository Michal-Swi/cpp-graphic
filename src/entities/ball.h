#include "point.h"
#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <vector>

enum VeritcalDirection {
	up,
	down,
	straight
};

class Ball : public Entity { 
	private:
	float x = 400, y = 0;
	float speed = 500;

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

	private:
	std::vector<Color> colors;
	Color current_color = WHITE;

	public:
	void load(Texture2D &texture) override {
		this->texture = texture;

		rec = {
			x, y,
			float(texture.width),
			float(texture.height)
		};

		colors = {
				WHITE,
				BLUE,
				RED,
				ORANGE,
				PINK,
				GREEN,
				MAGENTA,
				RAYWHITE,
				YELLOW,
				SKYBLUE,
				GOLD};
	}
	
	private:
	bool forward = true;
	VeritcalDirection veritcal_direction = up;	
	bool collides = false;
	Vector2 collision_point;
	Rectangle collision_rectangle;

	public:
	void set_collision_rectangle(Rectangle &collision_rectangle) override {
		this->collision_rectangle = collision_rectangle;
	}

	public:
	void set_collision_point(Vector2 &collision_point) 
		override {
		this->collision_point = collision_point;
	}

	public:
	void set_collides(const bool &collides) override {
		this->collides = collides;
	}

	private:
	float force = 1;

	private:
	void recalculate_force() {
		float temp = std::abs
			(collision_rectangle.y - collision_point.y);
		temp /= (collision_rectangle.y) / 4;

		force = 1 + temp;
	}

	private:
	void calculate_direction() {
		if (collision_point.y > collision_rectangle.y) {
			veritcal_direction = up;
			return;
		}

		veritcal_direction = down;
	}

	private:
	// This assumes that collision had happened
	bool is_inside_collision_rec() {
		bool screen_side = x < GetScreenWidth() / 2;
		
		int val;
		if (screen_side) {
		}
	}

	public: 
	void update(float &delta_time) override {
		if (collides) {
			forward = !forward;
			recalculate_force();
			calculate_direction();

			int index = GetRandomValue(0, 9);
			current_color = colors[index];
		}

		if (forward) {
			x += speed * delta_time * force;
		} else if (!forward) {
			x -= speed * delta_time * force;
		}
		
		switch (veritcal_direction) {
			case up:
				y += 5 * force;
				break;
			case down:
				y -= 5 * force;
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

		force = 1;
		forward = !forward;
		
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
		DrawTextureRec(texture, rec, {x, y}, current_color);
	}
};

