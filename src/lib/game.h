#include "./entity.h"
#include <cstdlib>
#include <memory>
#include <vector>
#include <raylib.h>

using entities = std::vector<Entity*>;

class Game {
	private:
	::entities entities;

	public: 
	void update() {
		for (auto &entity : entities) {
			entity->update();
		}
	}

	public:
	void start(::entities entities) {
		this->entities = entities;
	}

	public: 
	~Game() {
		for (auto &entity : entities) {
			free(entity);
		}
	}
};

