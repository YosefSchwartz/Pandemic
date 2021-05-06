#include <iostream>
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class OperationsExpert:public Player{
        public:
        OperationsExpert(Board& b, City city): Player(b, city){
            _role = "OperationsExpert";
        };
        Player& build() override;

    };

}