#include <iostream>
#include "Scientist.hpp"

using namespace std;

namespace pandemic{
        Scientist::Scientist(Board b, City c, int n) : Player(b,c), _n(n){
            this->_role = "Scientist";
        }
    void Scientist::discover_cure(Color disColor){
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
        cout<<"DISCOVER CURE TO: "+to_string(disColor)<<" FROM SCIENTIST"<<endl;

    }
}