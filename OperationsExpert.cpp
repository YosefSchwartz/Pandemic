#include "OperationsExpert.hpp"
#include <iostream>
#include "Board.hpp"

using namespace std;

namespace pandemic{
        OperationsExpert::OperationsExpert(Board b, City c) : Player(b,c){
            this->_role = "OperationsExpert";
        } 
                      
        void OperationsExpert::build(){
        // if(Board::researchStations[_currentCity] == 0){
        //     auto it = find(_hand.begin(),_hand.end(),_currentCity));
        //     if(*it > 0){
        //         _currentCity = desCity;
        //         _hand.earse(it);
        //     }
        // }
        // return;
        cout<<"BUILD RESEARCH STATION HERH : " + to_string(this->_currentCity) << "DO THIS BY OPERATIONSEXPERS"<<endl;
    }
}
