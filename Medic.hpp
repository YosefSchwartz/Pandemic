#include "Player.hpp"
#include "Board.hpp"
namespace pandemic{
    class Medic :public Player{
        public:
            Medic(Board b, City c);
            Medic& treat(City city);
            Medic& drive(City city);
            Medic& fly_direct(City city);
            Medic& fly_shuttle(City city);
            Medic& fly_charter(City city);

    };
}