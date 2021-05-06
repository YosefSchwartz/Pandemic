#include "Player.hpp"
#include "Board.hpp"
namespace pandemic{
    class GeneSplicer : public Player{
        public:
            GeneSplicer(Board& b, City city):Player(b,city){
                _role = "GeneSplicer";
            };
            Player& discover_cure(Color disColor, int x = 5) override;
    };
}