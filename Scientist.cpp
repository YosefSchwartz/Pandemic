#include <iostream>
#include "Scientist.hpp"

using namespace std;

namespace pandemic{

    Player& Scientist::discover_cure(Color disColor, int x){
        return Player::discover_cure(disColor,_n);
    }
}