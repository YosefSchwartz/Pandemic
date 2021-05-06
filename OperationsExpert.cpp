#include "OperationsExpert.hpp"
#include <iostream>
#include <algorithm>
#include "Board.hpp"

using namespace std;

namespace pandemic{
                    
        Player& OperationsExpert::build(){
            bool note = find(_hand.begin(),_hand.end(),_currentCity) != _hand.end();
            if(!note){
                 this->take_card(_currentCity);
            }
            auto& res = Player::build();
            
            if(note) {this->take_card(_currentCity);}
            return res;
    }
}
