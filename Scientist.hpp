#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Scientist : public Player{
            int _n;
        public:
            Scientist(Board b, City c, int n);
            void discover_cure(Color disColor);
            
    };
       
}