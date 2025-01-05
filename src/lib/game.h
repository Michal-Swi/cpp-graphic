#include "entity.h"
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>
#include <raylib.h>
#include <iostream>

using entities = std::vector<Entity*>;

class Game {
	private:
	::entities entities;

	public: 
	void update(float &delta_time) {
		for (auto &entity : entities) {
			entity->update(delta_time);
		}
	}

	public: 
	void draw() {
		ClearBackground(BLACK);
		BeginDrawing();

		for (auto &entity : entities) {
			entity->draw();
		}

		EndDrawing();
	}

	public:
	void start(::entities &entities) {
		this->entities = entities;
	}

	public: 
	~Game() {
		for (auto &entity : entities) {
			delete entity;
		}
	}
};

