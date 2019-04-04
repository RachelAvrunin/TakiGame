#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>
#include <string>

using namespace std;

class Player {
private:
	string name;
	int num_of_cards;
	vector <Card> myCards;



public:
	Player();
	Player(string name, int num_of_cards);
	Player(const Player& p);
	bool play(Card & cur,bool & flag);
	string getName();

};
#endif



