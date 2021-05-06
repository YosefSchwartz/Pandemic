#include "Dispatcher.hpp"
#include <iostream>

using namespace std;

namespace pandemic{

    Player& Dispatcher::fly_direct(City desCity){
        if(this->board.b[_currentCity].ResearchStation){
            this->_currentCity = desCity;
        } else {
            return Player::fly_direct(desCity);
        }
        return *this;
    }
}