#include "Player.h"
using namespace std;


Player::Player(){
    this->name="Moshe";
    this->num_of_cards=0;
}

Player::Player(string name, int num_of_cards){
    this->name=name;
    this->num_of_cards=num_of_cards;
    for(int i=0; i<num_of_cards;i++)
        this->myCards.push_back(Card::generate_card());
}

Player::Player(const Player& p){
    this->name=p.name;
    this->num_of_cards=p.num_of_cards;
    for(Card c : p.myCards)
        this->myCards.push_back(c);
}

string Player::getName(){
        return this->name;
}

bool Player::play( Card & cur){
    cout<<"curret: "<<cur<<"\n";
    cout<<this->name<<", your turn -\n";
    cout<<"Your cards: ";
    cout<<"\n";
    int i=1;
    for(Card c : this->myCards){
        cout<<"("<<i<<")"<<c<<" ";
        i++;
    }
    
    cin>>i;

    while((i>0)&&(i<=this->num_of_cards)&& (!cur.is_legal(myCards[i-1]))){
        cout<<"you can't put "<<myCards[i-1]<<"on "<<cur<<"\n";
        cin>>i;
    }

    if((i>0)&&(i<=this->num_of_cards)){

        cur=myCards[i-1];
        myCards.erase(myCards.begin()+i-1);
        return true;  

    }
    else{
        if(i>=0){
            num_of_cards++;
            myCards.push_back(Card::generate_card());
            return false; 
        }
        else{
            cout<<"This is an illegal selction, the game has ended!";
            //Game::set_gameOn(false);
            return false; 
        }
        
    }

}

