#include <map>
#include <optional>
#include <raylib.h>
#include <iostream>
#include <vector>
#include "./ball.h"

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

