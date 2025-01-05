#include "ball.h"
#include <raylib.h>

class Collision : public Entity {
	private:
	::entities entities;
	::entities collision_entities;

	public:
	void set_entities(const ::entities &entities) {
		this->entities = entities;
	}

	public:
	void add_event_listent(Entity *entity) {
		collision_entities.push_back(entity);
	}
	
	public:
	void update(float &delta_time) override {
		for (int i = 0; i < collision_entities.size(); i++) {
			for (int j = 0; j < entities.size(); j++) {
				if (collision_entities[i] == entities[j]) {
					continue;
				}
				
				std::cout << CheckCollisionRecs(collision_entities[i]->get_rec(),
						entities[j]->get_rec()) << std::endl;
			}
		}
	}
};

