#include <iostream>
#include <algorithm>
#include "Virologist.hpp"

using namespace std;

namespace pandemic{
        Player& Virologist::treat(City city){
            if(city == _currentCity){return Player::treat(city);}
            else{
                if(find(_hand.begin(),_hand.end(),city)!=_hand.end()){
                    City tmp = _currentCity;
                    _currentCity = city;
                    try{
                        this->Player::treat(city);
                    }catch (exception e){
                        _currentCity = tmp;
                        throw e;
                    }
                    _currentCity = tmp;
                    return *this; 
                } else {
                    throw invalid_argument("This Virologist doesn't have this card!\n");
                }
            }
    }
}
