#pragma once

#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <vector>

namespace pandemic
{
    class Player{
        
        protected:
            Board& board;
            std::string _role;
            pandemic::City _currentCity;
            std::vector<City> _hand;

            bool is_neighbors(City cur, City des);
            bool check_cure_exist(Color c);
            void update_cure(Color c);

        public:
            //Constructor

            Player(Board &b, City currentCity);

            virtual Player& drive(City city);
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color color, int x = 5);
            virtual Player& treat(City city);
            std::string role();
            Player& take_card(City city);  
    };
} // namespace pandemic
