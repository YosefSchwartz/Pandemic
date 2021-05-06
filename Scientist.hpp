#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Scientist : public Player{
            int _n;
        public:
            Scientist(Board& b, City city, int n):Player(b,city), _n(n){
                _role = "Scientist";
            };
            Player& discover_cure(Color disColor, int x=5) override;
            
    };
       
}