#include "rectangle.h"

class Points {
	private:
	Player *player1;
	Player *player2;

	public:
	void set_players(Player *&player1, Player *&player2) {
		this->player1 = player1;
		this->player2 = player2;
	}

	public:
	void add_point(const int &player) {
		if (player == 1) {
			player1->add_point();
		} else if (player == 2) {
			player2->add_point();
		}
	}
};

