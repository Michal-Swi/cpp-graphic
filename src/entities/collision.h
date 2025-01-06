#include "ball.h"
#include <cstddef>
#include <optional>
#include <algorithm>
#include <cmath>
#include <raylib.h>

struct circle {
	float x, y, radius;
};

class Collision : public Entity {
	private:
	::entities entities;
	::entities collision_entities;

	public:
	void set_entities(const ::entities &entities) {
		this->entities = entities;
	}

	public:
	void add_event_listener(Entity *entity) {
		collision_entities.push_back(entity);
	}

	std::optional<Vector2>
		check_collision(circle& circle, Rectangle& rect) {
		float closest_x = 
			std::clamp(circle.x, 
					rect.x - rect.width / 2.0f,
					rect.x + rect.width / 2.0f);
		float closest_y =  
			std::clamp(circle.y,
					rect.y - rect.height / 2.0f,
					rect.y + rect.height / 2.0f);

	    float distanceSquared = 
			(circle.x - closest_x) * (circle.x - closest_x) 
			+
	        (circle.y - closest_y) * (circle.y - closest_y);

		bool collision =
			distanceSquared <=
			(circle.radius * circle.radius);

		Vector2 vec = {closest_x, closest_y};
		if (collision) {
			return vec;
		}

		return std::nullopt;
	}
	
	public:
	void update(float &delta_time) override {
		for (auto &collision_entity : collision_entities) {
			bool was_collision = false;
			for (auto &entity : entities) {
				if (collision_entity == entity) {
					continue;
				}

				/*
				 * I use the built in rectangles
				 * wrong so the rec.x is not 
				 * the actual x of the rec
				 */

				float x = collision_entity->get_x();
				float y = collision_entity->get_y();

				Rectangle rec = collision_entity->get_rec();
				circle circle;
				circle.radius = rec.width / 2;
				circle.x = x + rec.width / 2;
				circle.y = y + rec.height / 2;
				
				x = entity->get_x();
				y = entity->get_y();

				Rectangle rec1;
				rec1 = entity->get_rec();
				rec1.x = x + rec1.width / 2;
				rec1.y = y + rec1.height / 2;

				std::optional<Vector2> result = 
					check_collision(circle, rec1);

				bool collision = result.has_value();

				if (collision) {
					Vector2 collision_point = result.value();
					was_collision = true;
					collision_entity->
						set_collision_point(collision_point);
					collision_entity->
						set_collides(true);
				}
			}

			if (!was_collision) {
				collision_entity->set_collides(false);
			}
		}
	}
};

