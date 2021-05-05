#include <iostream>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
    // map <City, int> b;

    int& Board::operator[](const City city){
        return this->b[city];
    }

    ostream& operator<<(ostream& os, Board &b){
        return os;
    }
    void Board::remove_cures(){
        cout<<"REMOVE CURES"<<endl;
    }

    bool Board::is_clean(){
        return false;
    }


}
