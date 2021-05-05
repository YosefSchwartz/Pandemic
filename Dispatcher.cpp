#include "Dispatcher.hpp"
#include <iostream>

using namespace std;

namespace pandemic{
    Dispatcher::Dispatcher(Board b, City c) : Player(b,c){
        this->_role = "Dispatcher";
    }
        Dispatcher& Dispatcher::fly_direct(City desCity){
        // auto it = find(_hand.begin(),_hand.end(),desCity));
        // if(*it > 0){
        //     _currentCity = desCity;
        //     _hand.earse(it);

        // }

        cout<<"FLY DIRECT TO: " + to_string(desCity)<< "USE BY DISPATCHER"<<endl;
        return *this;
    }
}