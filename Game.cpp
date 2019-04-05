#include "Game.h"

using namespace std;

	Game::Game(){
        numOfPlayers=0;
        currTurn=0;
        diraction=1; //go straight
        gameOn=true;
    }

    void Game::start(){
        cout<<"How many players?\n";
        cin>>numOfPlayers;
        if(numOfPlayers<=0){
            cout<<"illegal number of players!";
            return;
       }
        cout<<"How many cards?\n";
        int numOfCards;
        cin>>numOfCards;
        if(numOfCards<=0){
            cout<<"illegal number of cards!";
            return;
        }
        for(int i=0; i<numOfPlayers; i++){
            string name;
            cout<<"player number "<<i+1<<" name?\n";
            cin>>name;
            Player p (name,numOfCards);
            Game::myPlayers.push_back(p);
        }
        currCard=Card::generate_card();
        while(gameOn){
            bool played=myPlayers[currTurn].play(currCard,gameOn);\
            if(played && currCard.get_sign()==sign::STOP){
                if(diraction==1){
                    currTurn+=2;
                    checkTurn_Direction1(currTurn,numOfPlayers);
                }
                else{
                    currTurn-=2;
                    checkTurn_Direction2(currTurn,numOfPlayers);
                }
            }
            else if(played && currCard.get_sign()==sign::CD){
                if(diraction==1){
                    diraction=0;
                    currTurn--;
                    checkTurn_Direction2(currTurn,numOfPlayers);
                 
                }
                else{
                    diraction=1;
                    currTurn++;
                    checkTurn_Direction1(currTurn,numOfPlayers);   
                }
           
            }
            else if(currCard.get_sign()!=sign::PLUS || !played){
                if(diraction==1){
                    currTurn++;
                    checkTurn_Direction1(currTurn,numOfPlayers);
                }
                else{
                    currTurn--;
                    checkTurn_Direction2(currTurn,numOfPlayers);
                }                   
            }

        }
        

    }

void Game::checkTurn_Direction1( int & turn, const int & pNum){
    while(turn>=pNum)
        turn-=pNum;
}

void Game::checkTurn_Direction2( int & turn, const int & pNum){
    while(turn<=pNum)
        turn+=pNum;
}

