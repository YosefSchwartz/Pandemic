#include <iostream>
#include "Researcher.hpp"

using namespace std;

namespace pandemic{

    Player& Researcher::discover_cure(Color disColor, int x){
        bool note = this->board.b[_currentCity].ResearchStation;
        if(!note){this->board.b[_currentCity].ResearchStation = true;}
        try{
            this->Player::discover_cure(disColor);
        } catch (exception e){
            this->board.b[_currentCity].ResearchStation = note;
            throw e;
        }
        this->board.b[_currentCity].ResearchStation = note;
        return *this;
    }
}