#include <iostream>
#include "Medic.hpp"

using namespace std;

namespace pandemic {
    Medic::Medic(Board b, City c) : Player(b,c){
        this->_role = "Medic";
    }

    Medic& Medic::treat(City city){
        // auto p = find(Board::diseaseLevel.begin(),Board::diseaseLevel.end(),_currentCity);

        // if(*p = 0){out_of_range("This city is clean!\n");}

        // Color c = Board::cures[Board::cityToColor[*p]];
        // if(Board::cures[c] == 1){Board::diseaseLevel[*p] = 0;}
        // else {Board::diseaseLevel[*p]--;}
        cout<< "TREAT: "+to_string(city)<< "BY MEDIC"<<endl;
        return *this;
    }
    Medic& Medic::drive(City city){
        cout<< "DRIVE: "+to_string(city)<< "BY MEDIC"<<endl;
        return *this;
    }
    Medic& Medic::fly_direct(City city){
        cout<< "FLY DIRECT: "+to_string(city)<< "BY MEDIC"<<endl;
        return *this;
    }
    Medic& Medic::fly_shuttle(City city){
        cout<< "FLY SHUTTLE: "+to_string(city)<< "BY MEDIC"<<endl;
        return *this;
    }
    Medic& Medic::fly_charter(City city){
        cout<< "FLY CHARTER: "+to_string(city)<< "BY MEDIC"<<endl;
        return *this;
    }


}