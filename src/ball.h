#include "lib/game.h"
#include <raylib.h>

class Ball : public Entity { 
	private:
	float x = 0, y = 0;

	private:
	Texture2D texture;
	Image img;
	Rectangle rec;

	public:
	void load() override {
		img = LoadImage("../files/circle.png");
		texture = LoadTextureFromImage(img);

		rec = {
			x, y,
			float(texture.width),
			float(texture.height)
		};
	}
	
	public: 
	void update() override {
		auto n = IsKeyDown('W'); 

		if (n) {
			rec.x += 5;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawTextureRec(texture, rec, {rec.x, rec.y}, WHITE);
		EndDrawing();
	}
};

