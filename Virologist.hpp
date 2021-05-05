#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{
    class Virologist : public Player{
        public:
            Virologist(Board b, City c);
            Virologist& treat(City city);
            

    };
}