#include <iostream>
#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic{
    GeneSplicer::GeneSplicer(Board b, City c) : Player(b,c){
        this->_role = "GeneSplicer";
    }
    void GeneSplicer::discover_cure(Color disColor){
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
        cout<<"DISCOVER CURE TO: "+to_string(disColor)<<" BY GeneSplicer"<<endl;

    }
    
}