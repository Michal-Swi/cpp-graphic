#include <map>
#include <optional>
#include <raylib.h>
#include <iostream>
#include <vector>
#include "./ball.h"

/*
class Game {
	enum TextureName {
		circle_texture,
	};

	enum ImageName {
		circle_image,
	};

	private:
	std::map<TextureName, Texture2D> textures;
	std::map<ImageName, Image> images;
	Color background_color = BLACK;

	private:
	void fill_textures() {
		Texture2D circle;

		textures[TextureName::circle_texture] = circle;
	}

	private:
	void fill_images() {
		Image circle;
		circle = LoadImage("../files/circle.png");

		images[ImageName::circle_image] = circle;
	}

	private: 
	void game_loop() {
		textures[circle_texture] = LoadTextureFromImage(images[circle_image]);

		Rectangle rec = {
			0, 0, 
			float(textures[circle_texture].width),
			float(textures[circle_texture].height)
		};

		while (true) {
			BeginDrawing();
			
			ClearBackground(background_color);
			DrawTextureRec(textures[circle_texture], rec, Vector2{0, 0}, WHITE);

			if (IsKeyPressed(KEY_ESCAPE)) {
				return;
			}

			EndDrawing();
		}
	}

	public: 
	void start() {
		InitWindow(1920, 1080, "test");
		SetTargetFPS(60);
		fill_textures();
		fill_images();
		game_loop();
	}
};
*/
 
int main() {
	InitWindow(1920, 1080, "test");
	SetTargetFPS(60);

	::entities entities;
	
	auto ball = new Ball;
	ball->load();
	entities.push_back(ball);

	Game game;
	game.start(entities);

	while (true) {
		if (IsKeyPressed(KEY_ESCAPE)) {
			return 0;
		}

		game.update();
	}

	return 0;
}

