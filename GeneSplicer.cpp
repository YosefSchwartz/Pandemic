#include <iostream>
#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic{

    Player& GeneSplicer::discover_cure(Color disColor, int x){
        if(check_cure_exist(disColor)) {
            cout<<"Cure to this color already exist!"<<endl;
            return *this;
        } else {
            if(!this->board.b[_currentCity].ResearchStation){
                throw invalid_argument("There isn't research station here!\n");
            } else if(_hand.size() >= 5){
                for(unsigned int i = 0; i<5;++i){
                    _hand.pop_back();
                }
                update_cure(disColor);
            } else {
                throw out_of_range("You don't have 5 cards of this color!\n");
            }
        }
        return *this;
    }
    
}