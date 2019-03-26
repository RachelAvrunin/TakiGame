#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>

using namespace std;

class Game {
private:
	int numOfPlayers;
	vector <Player> myPlayers;
	Card currCard;
	int currTurn;
	int diraction;

public:

//	static bool gameOn;

	Game();
	void start();
//	static void set_gameOn(bool);
};
#endif




