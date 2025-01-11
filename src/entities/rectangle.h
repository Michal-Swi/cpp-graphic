#include "../lib/game.h"
#include <raylib.h>
#include <raymath.h>

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

	private:
	int points = 0;

	public:
	void add_point() {
		points++;
	}
	
	enum ScreenSide {
		left, right
	};

	private:
	ScreenSide get_screen_side(const float &x_pos) {
		if (x_pos < GetScreenWidth() / 2) {
			return ScreenSide::left;
		}

		return ScreenSide::right;
	}

	public: 
	void update(float &delta_time) override {
		ScreenSide mouse_screen_side = 
			get_screen_side(GetMouseX());

		ScreenSide rec_screen_side = 
			get_screen_side(x);

		if (mouse_screen_side != rec_screen_side) {
			return;
		}

		float smoothnes = 0.6;
		y = Lerp(y, GetMouseY(), smoothnes);

		if (y < 0) {
			y = 1;
		} else if (y + rec.height >= GetScreenHeight()) {
			y = GetScreenHeight() - rec.height;
		}
	}

	public:
	void draw() override {
		DrawTextureRec(texture, rec, {x, y}, WHITE);	
		
		bool substract = (x < GetScreenWidth() / 2);
		int pos_offset = substract ? -150 : 150;
		int offset = 50;

		DrawText(std::to_string(points).c_str(), 
				GetScreenWidth() / 2 + pos_offset,
				offset,
				offset, 
				WHITE);
	}
};

