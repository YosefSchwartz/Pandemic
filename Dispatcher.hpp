#include "Player.hpp"
#include "Board.hpp"
namespace pandemic{

    class Dispatcher : public Player{
        public:
            Dispatcher(Board& b, City city) : Player(b,city){
                _role = "Dispatcher";
            };
            
            Player& fly_direct(City desCity) override;
    };
}