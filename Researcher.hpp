#include "Player.hpp"
#include "Board.hpp"
namespace pandemic{
    class Researcher : public Player{
        public:
            Researcher(Board& b, City city):Player(b,city){
                _role = "Researcher";
            };
            Player& discover_cure(Color disColor, int x = 5) override;
            
    };
}