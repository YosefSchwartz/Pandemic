#pragma once
#include <vector>
#include <map>
#include "Color.hpp"
#include "City.hpp"


namespace pandemic{
    class Board{
        public:
            std::map<City,int> b;
            void remove_cures();
            int& operator[](const City city);
            bool is_clean();
            friend std::ostream& operator<<(std::ostream& os, Board &b);
    };
}