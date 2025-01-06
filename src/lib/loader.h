#include <string>
#include <raylib.h>
#include "../entities/entities.h"

class Loader {
	private:
	Texture2D texture;

	public: 
	Texture2D load_texture_from_image_path
		(std::string &path) {
		Texture2D texture;

		Image img = LoadImage(path.c_str());
		texture = LoadTextureFromImage(img);

		return texture;
	}

	public:
	Player *load_player(std::string &path_to_image) {
		Player *player = new Player;

		texture =
			load_texture_from_image_path
			(path_to_image);

		player->load(texture);
		return player;
	}

	public:
	Ball *load_ball(std::string &path_to_image) {
		Ball *ball = new Ball;

		texture = 
			load_texture_from_image_path
			(path_to_image); 

		ball->load(texture);
		return ball;
	}

	public:
	entities load_entities() {
		Ball *ball = new Ball;
		std::string path = "../files/white_circle.png";
		ball = load_ball(path);

		Player *player1 = new Player,
			   *player2 = new Player;
		path = "../files/thinner_white_rectangle_20px.png";
		player1 = load_player(path);
		player2 = load_player(path);

		player2->set_x(GetScreenWidth() - texture.width - 50);
		player1->set_x(50);

		ball->load_points(player1, player2);

		Collision *collision = new Collision;
		collision->add_event_listener(ball);

		entities entities;
		entities.push_back(ball);
		entities.push_back(player1);
		entities.push_back(player2);
		
		collision->set_entities(entities);
		entities.push_back(collision);

		return entities;
	}
};

