#include "Player.hpp"
#include "Board.hpp"
namespace pandemic{

    class Dispatcher : public Player{
        public:
            Dispatcher(Board b, City city);
            Dispatcher& fly_direct(City desCity);
    };
}