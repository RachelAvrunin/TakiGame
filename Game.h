#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
#include <string>
#include <stdbool.h>

using namespace std;

class Game {

private:
	int numOfPlayers;
	vector <Player> myPlayers;
	Card currCard;
	int currTurn;
	int diraction;
	bool gameOn;
	void checkTurn_Direction1( int & turn, const int & pNum);
	void checkTurn_Direction2( int & turn, const int & pNum);
	Game(const Game & g);
	Game operator = (const Game & g);

public:

	Game();
	void start();

};
#endif




