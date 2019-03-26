#include "Game.h"

int main() {


	Player p("ANNA",7);
	Card c(Card::generate_card());
	p.play(c);
	p.play(c);

	/*srand(time(NULL));
	Game game;
	game.start();
	return 0;*/
}