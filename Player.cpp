#include "Player.h"

using namespace std;


Player::Player(){
    this->name="Moshe";
    this->num_of_cards=0;
}

Player::Player(const string name, const int num_of_cards){
    this->name=name;
    this->num_of_cards=num_of_cards;
    for(int i=0; i<num_of_cards; i++)
        this->myCards.push_back(Card::generate_card());
}

Player::Player(const Player& p){
    this->name=p.name;
    this->num_of_cards=p.num_of_cards;
    for(int i=0; i<p.num_of_cards;i++){
        this->myCards.push_back(p.myCards.at(i));
    }
}
Player Player::operator = (const Player & p){
    this->name=p.name;
    this->num_of_cards=p.num_of_cards;
    for(int i=0; i<p.num_of_cards;i++){
        this->myCards.push_back(p.myCards.at(i));
    }
}


bool Player::play(Card & cur, bool & gameOn){
    cout<<"current: "<<cur<<"\n";
    cout<<this->name<<", your turn -\n";
    cout<<"Your cards: ";
    for(int i=0; i<this->num_of_cards;i++){
        cout<<"("<<i+1<<")"<<this->myCards.at(i)<<" ";
    }
    cout<<"\n";
    int i=0;
    cin>>i;

    while((i>0)&&(i<=this->num_of_cards)&& (!cur.is_legal(myCards[i-1]))){
        cout<<"You can't put "<<myCards[i-1]<<" on "<<cur<<"\n";
        cin>>i;
    }

    if((i>0)&&(i<=this->num_of_cards)){
        cur=myCards[i-1];
        myCards.erase(myCards.begin()+i-1);
        num_of_cards--;
        if(num_of_cards==0){
            cout<<this->name<<" wins!";
            gameOn=false;
        }
        return true;
    }

    else{
            num_of_cards++;
            myCards.push_back(Card::generate_card());
            return false; 
    }

}