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
            std::string _role;
            pandemic::City _currentCity;
            std::vector<City> _hand;


        public:
            //Constructor
            Player(Board &b, City currentCity);

            virtual Player& drive(City city);
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual void build();
            virtual void discover_cure(Color color);
            virtual Player& treat(City city);
            std::string role();
            Player& take_card(City city);  
    };
} // namespace pandemic
