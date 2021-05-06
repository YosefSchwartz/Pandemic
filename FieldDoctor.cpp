#include <iostream>
#include <algorithm>
#include "Board.hpp"
#include "City.hpp"
#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic{
    
    Player& FieldDoctor::treat(City city){
        auto p = this->board.b[_currentCity].neighbors;
        if(_currentCity == city){
            return Player::treat(city);
        }
        if(find(p.begin(),p.end(),city) != p.end()){
            City tmp =_currentCity;
            _currentCity = city;
            try{
            this->Player::treat(city);
            }catch (exception e){
                _currentCity = tmp;
                throw e;
            }
            _currentCity = tmp;
            return *this;
        }
        throw out_of_range("You are not in this city or one of her neighbors!\n");
    }
}
