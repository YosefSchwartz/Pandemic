#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class FieldDoctor : public Player{
        public:
            FieldDoctor(Board& b, City city): Player(b, city){
                _role = "FieldDoctor";
            };
            Player& treat(City city) override;

    };
}