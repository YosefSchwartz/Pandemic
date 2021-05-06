#include <iostream>
#include "Medic.hpp"

using namespace std;

namespace pandemic {
    Medic::Medic(Board& b, City city) : Player(b,city){
                _role = "Medic";
                this->board[city] = 0;
    }
    Player& Medic::treat(City city){
        this->board[city] = 0;
        return *this;
    }
    Player& Medic::drive(City city){
        auto& res = Player::drive(city);
        if(this->board.b[city].Cure){ board[city] = 0;}
        return res;
    }
    Player& Medic::fly_direct(City city){
        auto& res = Player::fly_direct(city);
        if(this->board.b[city].Cure){ board[city] = 0;}
        return res;
    }
    Player& Medic::fly_shuttle(City city){
        auto& res = Player::fly_shuttle(city);
        if(this->board.b[city].Cure){ board[city] = 0;}
        return res;
    }
    Player& Medic::fly_charter(City city){
        auto& res = Player::fly_charter(city);
        if(this->board.b[city].Cure){ board[city] = 0;}
        return res;
    }


}