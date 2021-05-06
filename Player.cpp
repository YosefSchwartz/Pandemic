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
    Player::Player(Board& b, City currentCity) : board(b), _currentCity(currentCity){
        _role = "Player";
    };
    
    bool Player::is_neighbors(City cur, City des){
        auto v = board.b[cur].neighbors;
        if(find(v.begin(),v.end(),des) != v.end()) {return true;}
        return false;
    }

    //Drive player to given city iff is in the neighbors list
    Player& Player::drive(City desCity){
        if(is_neighbors(_currentCity ,desCity)){
            this->_currentCity = desCity;
        }
        else{
            throw out_of_range("The city: "+this->board.name[desCity]+
                        " and " + this->board.name[this->_currentCity]+
                        " doesn't Connected");
        }
        cout<< this->role()<<" Drive to "<<this->board.name[desCity];
        return *this;
    }

    //Fly to given city iff the player have destination city card in their hand
    Player& Player::fly_direct(City desCity){
        auto it = find(_hand.begin(),_hand.end(),desCity);
        if(it < _hand.end()){
            _currentCity = desCity;
            this->_hand.erase(it);
        } else {
            throw invalid_argument("Flight aborted!\nYou don't have "+this->board.name[desCity]+" card!\n");    
        }
        cout<< this->role()<<" Fly to "<<this->board.name[desCity]<<endl;

        return *this;
    }
    
    //Fly to given any city iff player had current city card in their hand
    Player& Player::fly_charter(City desCity){
        auto it = find(_hand.begin(),_hand.end(),_currentCity);
        if(it < _hand.end()){
            _currentCity = desCity;
            this->_hand.erase(it);
        } else {
            throw invalid_argument("Flight aborted!\n You don't have "+this->board.name[_currentCity]+" card!\n");    
        }
        cout<< this->role()<<" Fly to "<<this->board.name[desCity];
        return *this;
    }

    // fly to onther city, iff both have research station
    Player& Player::fly_shuttle(City desCity){
        if(this->board.b[_currentCity].ResearchStation &&
            this->board.b[desCity].ResearchStation){
            _currentCity = desCity; 
        } else {
            throw out_of_range("One of these cities doesn't have research station!\n");
        }
        cout<< this->role()<<" Fly to "<<this->board.name[desCity];
        return *this;    
    }

    /*
    Build a research station in this city, if player have current city card.
    If this city already had research station, nothing will be done. 
    */
    Player& Player::build(){
        if(this->board.b[_currentCity].ResearchStation){
            cout<<"Research staion already exist!\n"<<endl;
        } else {
            auto it = find(_hand.begin(),_hand.end(),_currentCity);
            if(it < _hand.end()){
                this->board.b[_currentCity].ResearchStation = true;
                this->_hand.erase(it);
            } else {
                throw invalid_argument("you don't have "+this->board.name[_currentCity]+" card!\n");    
            }
        }
        cout<<this->role()<< " build in "<<this->board.name[_currentCity]<<endl;;

        return *this;
    }
    bool Player::check_cure_exist(Color c){
        map<City,cityData>::iterator itr;
        for(itr = this->board.b.begin(); itr != this->board.b.end();++itr){
            if(itr->second.color == c && itr->second.Cure == true) {
            return true;}
        }
        return false;
    }
    void Player::update_cure(Color c){
        map<City,cityData>::iterator itr;
        for(itr = board.b.begin(); itr != board.b.end();++itr){
            if(itr->second.color == c){itr->second.Cure = true;}
        }
    }
    //Discover a cure to specific color by throw any 5 cards whit this color 
    Player& Player::discover_cure(Color disColor, int x){
        if(check_cure_exist(disColor)) {
            cout<<"Cure to this color already exist!"<<endl;
            return *this;
        } else {
            if(!this->board.b[_currentCity].ResearchStation){
                throw invalid_argument("There isn't research station here!\n");
            }
            vector<City>::iterator itr;
            vector<City> temp;
            for(auto& itr : _hand){
                    if(board.b[itr].color == disColor){
                        temp.push_back(itr);
                    }
            }
            if(temp.size() >= x){
                for(unsigned int i = 0; i<x;++i){
                    auto p = find(_hand.begin(),_hand.end(),temp[i]);
                    _hand.erase(p);
                }
                update_cure(disColor);
                cout<<this->role()<< " dicover cure "<<endl;;

                return *this;
            } else {
                throw out_of_range("You don't have 5 cards of this color!\n");
            }
        }
    }

    //Treat the disease by one cube.
    Player& Player::treat(City city){
        if(_currentCity != city) {throw invalid_argument("You are not in this city!\n");}
        if(this->board[city] == 0) {throw out_of_range("No disease in this city!\n");}
        if(this->board.b[city].Cure){
            board[city] = 0;}
        else {
            this->board.b[city].diseaseLevel--;}
        cout<<this->role()<< "treat in " <<this->board.name[city]<<endl;;
        return *this;
    }

    //Return the role of this player
    std::string Player::role(){
        return _role;
    }

    //Collect card to _hand
    Player& Player::take_card(City city){
        cout<<this->role()<< " TAKE CARD " + this->board.name[city]<<endl;
        if(find(_hand.begin(),_hand.end(),city) == _hand.end()){
            _hand.push_back(city);
        }
        else{
            //cout<<"You already had this card!\n";
        }
        return *this;
    }

} // namespace pandemic
