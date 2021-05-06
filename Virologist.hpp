#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class Virologist : public Player{
        public:
            Virologist(Board& b, City city): Player(b, city){
                _role = "Virologist";
            };
            Player& treat(City city) override;
            

    };
}