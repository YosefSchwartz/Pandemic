#pragma once
#include <vector>
#include <map>
#include "Color.hpp"
#include "City.hpp"


namespace pandemic{
    struct cityData
    {
        int diseaseLevel;
        bool ResearchStation;
        std::vector<City> neighbors;
        Color color;
        bool Cure;
    };
    
    class Board{
        public:
            Board();
            std::vector<std::string> colors;
            std::vector <std::string> name;
            std::map<City,cityData> b;
            Board& remove_cures();
            int& operator[](const City city);
            bool is_clean();
            friend std::ostream& operator<<(std::ostream& os, Board &b);
    };
}