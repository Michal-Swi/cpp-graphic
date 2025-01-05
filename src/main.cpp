#include <cerrno>
#include <raylib.h>
#include "lib/loader.h"

int main() {
	InitWindow(1920, 1080, "Gra");

	const int fps = 60;
	SetTargetFPS(fps);

	Loader loader;
	::entities entities = loader.load_entities();

	Game game;
	game.start(entities);

	float delta_time;
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_ESCAPE) or 
				IsKeyDown(KEY_ESCAPE)) {
			return 0;
		}

		delta_time = GetFrameTime();
		
		game.update(delta_time);
		game.draw();
	}

	return 0;
}

