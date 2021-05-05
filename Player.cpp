#include <iostream>
#include <vector>
#include <algorithm>

#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic
{
    Player::Player(Board &b, City currentCity){
        // this->_currentCity = currentCity;
        // this->_hand = new vector<City>;
    }
    //Drive player to given city iff is in the neighbors list
    Player& Player::drive(City desCity){
        // if(Board::is_neighbors(_currentCity ,desCity)){
        //     this->_currentCity = desCity;
        // }

        cout<<"DRIVE TO: " + to_string(desCity)<<endl;
        return *this;
    }

    //Fly to given city iff the player have destination city card in their hand
    Player& Player::fly_direct(City desCity){
        // auto it = find(_hand.begin(),_hand.end(),desCity));
        // if(*it > 0){
        //     _currentCity = desCity;
        //     _hand.earse(it);

        // }

        cout<<"FLY DIRECT TO: " + to_string(desCity)<<endl;
        return *this;
    }
    
    //Fly to given any city iff player had current city card in their hand
    Player& Player::fly_charter(City desCity){
        // auto it = find(_hand.begin(),_hand.end(),_currentCity));
        // if(*it > 0){
        //     _currentCity = desCity;
        //     _hand.earse(it);

        // }
        cout<<"FLY CHARTER TO: " + to_string(desCity)<<endl;
        return *this;
    }

    // fly to onther city, iff both have research station
    Player& Player::fly_shuttle(City desCity){
        // if(Board::researchStations[desCity] == true &&
        //     Board::researchStations[_currentCity] ==true)
        //     _currentCity = desCity; 
        cout<<"FLY SHUTTLE TO: " + to_string(desCity)<<endl;

        return *this;    
    }

    /*
    Build a research station in this city, if player have current city card.
    If this city already had research station, nothing will be done. 
    */
    void Player::build(){
        // if(Board::researchStations[_currentCity] == 0){
        //     auto it = find(_hand.begin(),_hand.end(),_currentCity));
        //     if(*it > 0){
        //         _currentCity = desCity;
        //         _hand.earse(it);
        //     }
        // }
        // return;
        cout<<"BUILD RESEARCH STATION HERH : " + to_string(this->_currentCity)<<endl;

    }

    //Discover a cure to specific color by throw any 5 cards whit this color 
    void Player::discover_cure(Color disColor){
        // if(Board::cures[disColor]== true){return;}

        // vector<City> cards;
        // //Try to collect 5 cards of this color
        // for(auto i : _hand){
        //     if(Board::cityToColor[*i].color == disColor){
        //         cards->push_back(*i);
        //     }
        // }
        // //Check size if cards vector
        // if(cards.size() == 5){
        //     for(auto &i : cards){
        //         _hand.erase(i);
        //     }
        //     Board::cures[disColor] = true;
        // }
        // else{
        //     throw out_of_range("Under 5 cards of this color!\n");
        // }
        cout<<"DISCOVER CURE TO: "+to_string(disColor)<<endl;

    }

    //Treat the disease by one cube.
    Player& Player::treat(City city){
        // auto p = find(Board::diseaseLevel.begin(),Board::diseaseLevel.end(),_currentCity);

        // if(*p = 0){out_of_range("This city is clean!\n");}

        // Color c = Board::cures[Board::cityToColor[*p]];
        // if(Board::cures[c] == 1){Board::diseaseLevel[*p] = 0;}
        // else {Board::diseaseLevel[*p]--;}
        cout<< "TREAT: "+to_string(city)<<endl;
        return *this;
    }

    //Return the role of this player
    std::string Player::role(){
        return "ROLE";
    }

    //Collect card to _hand
    Player& Player::take_card(City city){
        // _hand->push_back(city);
        cout<<"DROP: "+to_string(city)<<endl;
        return *this;
    }

} // namespace pandemic
