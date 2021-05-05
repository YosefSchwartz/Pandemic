#include "Player.hpp"
#include "Board.hpp"
namespace pandemic{
    class GeneSplicer : public Player{
        public:
            GeneSplicer(Board b, City c);
            void discover_cure(Color disColor);
    };
}