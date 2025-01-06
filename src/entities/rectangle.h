#include "../lib/game.h"
#include <raylib.h>

class Player : public Entity {
	private:
	float x = 0, y = 0;
	
	public:
	void set_x(const float &x) {
		this->x = x;
	}

	public:
	void set_y(const float &y) {
		this->y = y;
	}

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

	public: 
	void update(float &delta_time) override {
		y = GetMouseY();
	}

	public:
	void draw() override {
		DrawTextureRec(texture, rec, {x, y}, WHITE);	
	}
};

