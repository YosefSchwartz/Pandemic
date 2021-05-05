#include <iostream>
#include "Virologist.hpp"

using namespace std;

namespace pandemic{
        Virologist::Virologist(Board b, City c) : Player(b,c){
            this->_role = "Virologist";
        }
        Virologist& Virologist::treat(City city){
        // auto p = find(Board::diseaseLevel.begin(),Board::diseaseLevel.end(),_currentCity);

        // if(*p = 0){out_of_range("This city is clean!\n");}

        // Color c = Board::cures[Board::cityToColor[*p]];
        // if(Board::cures[c] == 1){Board::diseaseLevel[*p] = 0;}
        // else {Board::diseaseLevel[*p]--;}
        cout<< "TREAT: "+to_string(city)<<" BY VIROLOGIST"<<endl;
        return *this;
    }
}
