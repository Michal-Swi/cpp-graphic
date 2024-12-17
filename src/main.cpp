#include <optional>
#include <raylib.h>
#include <iostream>

enum Error {
	Ok,				// No error
	ImageNotLoaded,
	TextureNotLoaded,
};

class Circle {
	private:
	static Image circle_image;
	static Texture2D circle_texture;	
	static Rectangle circle_rectangle;

	public:
	static std::optional<Error> 
			load_circle_image(const std::string &path) {
		circle_image = LoadImage(path.c_str());
		
		bool not_loaded = circle_image.height == 0; 
		not_loaded += (circle_image.width == 0);

		if (not_loaded) {
			return std::nullopt;
		}

		return std::make_optional(Error::Ok);
	}

	public:
	static std::optional<Error> load_circle_texture() {
		circle_texture = LoadTextureFromImage(circle_image);

		bool not_loaded = (circle_texture.id == 0);

		if (not_loaded) {
			return std::nullopt;
		}

		return std::make_optional(Error::Ok);
	}

	public:
	static std::optional<Error> 
	load_circle_rectangle (const Vector2 &coordinates) {
		float texture_width, texture_height; 
		texture_width = 
			static_cast<float>(circle_texture.width);
		texture_height =
			static_cast<float>(circle_texture.height);

		circle_rectangle = {
			coordinates.x,
			coordinates.y,
			texture_width,
			texture_height
		};

		return std::make_optional(Error::Ok);
	}

	public:
	static Image get_circle_image() {
		return circle_image;
	}

	static Texture get_circle_texture() {
		return circle_texture;
	}

	static Rectangle get_circle_rectangle() {
		return circle_rectangle;
	}
};

int main() {
	InitWindow(1920, 1080, "test");
	SetTargetFPS(60);
	
	Circle circle;
	auto result = 
		circle.load_circle_image("../files/circle.png");
	
	if (!result.has_value()) {
		std::cout << "Error" << std::endl;
	}

	result = circle.load_circle_texture();
	
	if (!result.has_value()) {
		std::cout << "Error" << std::endl;
	}

	circle.load_circle_rectangle({0.f, 0.f});

	while (true) {
		BeginDrawing();

		ClearBackground(BLACK);
		DrawTextureRec(circle.get_circle_texture(), circle.get_circle_rectangle(), {0.f, 0.f}, WHITE);

		int key = GetKeyPressed();
		if (key == KEY_ESCAPE) {
			return 0;
		}

		EndDrawing();
	}

	return 0;
}

