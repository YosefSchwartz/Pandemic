#include <iostream>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
    map <City, cityData> b;
    
    Board::Board(){
        this->name = {"Algiers", "Atlanta", "Baghdad", "Bangkok", "Beijing",
        "Bogota", "BuenosAires", "Cairo", "Chennai", "Chicago",
        "Delhi", "Essen", "HoChiMinhCity", "HongKong", "Istanbul",
        "Jakarta", "Johannesburg", "Karachi", "Khartoum", "Kinshasa", 
        "Kolkata", "Lagos", "Lima", "London", "LosAngeles",
        "Madrid", "Manila", "MexicoCity", "Miami", "Milan",
        "Montreal", "Moscow", "Mumbai", "NewYork", "Osaka",
        "Paris", "Riyadh", "SanFrancisco", "Santiago", "SaoPaulo",
        "Seoul", "Shanghai", "StPetersburg", "Sydney", "Taipei",
        "Tehran", "Tokyo", "Washington"};

        this->colors = {"Red", "Yellow", "Black", "Blue"};

        this->b[Algiers].neighbors = {Madrid, Paris, Istanbul, Cairo};
        this->b[Atlanta].neighbors = {Chicago, Miami,Washington};
        this->b[Baghdad].neighbors = {Tehran, Istanbul, Cairo, Riyadh, Karachi};
        this->b[Bangkok].neighbors = {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong};
        this->b[Beijing].neighbors = {Shanghai, Seoul};
        this->b[Bogota].neighbors = {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires};
        this->b[BuenosAires].neighbors = {Bogota, SaoPaulo};
        this->b[Cairo].neighbors = {Algiers, Istanbul, Baghdad, Khartoum, Riyadh};
        this->b[Chennai].neighbors = {Mumbai, Delhi, Kolkata, Bangkok, Jakarta};
        this->b[Chicago].neighbors = {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal};
        this->b[Delhi].neighbors = {Tehran, Karachi, Mumbai, Chennai, Kolkata};
        this->b[Essen].neighbors = {London, Paris, Milan, StPetersburg};
        this->b[HoChiMinhCity].neighbors = {Jakarta, Bangkok, HongKong, Manila};
        this->b[HongKong].neighbors = {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei};
        this->b[Istanbul].neighbors = {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow};
        this->b[Jakarta].neighbors = {Chennai, Bangkok, HoChiMinhCity, Sydney};
        this->b[Johannesburg].neighbors = {Kinshasa, Khartoum};
        this->b[Karachi].neighbors = {Tehran, Baghdad, Riyadh, Mumbai, Delhi};
        this->b[Khartoum].neighbors = {Cairo, Lagos, Kinshasa, Johannesburg};
        this->b[Kinshasa].neighbors = {Lagos, Khartoum, Johannesburg};
        this->b[Kolkata].neighbors = {Delhi, Chennai, Bangkok, HongKong};
        this->b[Lagos].neighbors = {SaoPaulo, Khartoum, Kinshasa};
        this->b[Lima].neighbors = {MexicoCity, Bogota, Santiago};
        this->b[London].neighbors = {NewYork, Madrid, Essen, Paris};
        this->b[LosAngeles].neighbors = {SanFrancisco, Chicago, MexicoCity, Sydney};
        this->b[Madrid].neighbors = {London, NewYork, Paris, SaoPaulo, Algiers};
        this->b[Manila].neighbors = {Taipei, SanFrancisco, HoChiMinhCity, Sydney};
        this->b[MexicoCity].neighbors = {LosAngeles, Chicago, Miami, Lima, Bogota};
        this->b[Miami].neighbors = {Atlanta, MexicoCity, Washington, Bogota};
        this->b[Milan].neighbors = {Essen, Paris, Istanbul};
        this->b[Montreal].neighbors = {Chicago, Washington, NewYork};
        this->b[Moscow].neighbors = {StPetersburg, Istanbul, Tehran};
        this->b[Mumbai].neighbors = {Karachi, Delhi, Chennai};
        this->b[NewYork].neighbors = {Montreal, Washington, London, Madrid};
        this->b[Osaka].neighbors = {Taipei, Tokyo};
        this->b[Paris].neighbors = {Algiers, Essen, Madrid, Milan, London};
        this->b[Riyadh].neighbors = {Baghdad, Cairo, Karachi};
        this->b[SanFrancisco].neighbors = {LosAngeles, Chicago, Tokyo, Manila};
        this->b[Santiago].neighbors = {Lima};
        this->b[SaoPaulo].neighbors = {Bogota, BuenosAires, Lagos, Madrid};
        this->b[Seoul].neighbors = {Beijing, Shanghai, Tokyo};
        this->b[Shanghai].neighbors = {Beijing, HongKong, Taipei, Seoul, Tokyo};
        this->b[StPetersburg].neighbors = {Essen, Istanbul, Moscow};
        this->b[Sydney].neighbors = {Jakarta, Manila, LosAngeles};
        this->b[Taipei].neighbors = {Shanghai, HongKong, Osaka, Manila};
        this->b[Tehran].neighbors = {Baghdad, Moscow, Karachi, Delhi};
        this->b[Tokyo].neighbors = {Seoul, Shanghai, Osaka, SanFrancisco};
        this->b[Washington].neighbors = {Atlanta, NewYork, Montreal, Miami};


        this->b[Algiers].color = Black;
        this->b[Atlanta].color = Blue;
        this->b[Baghdad].color = Black;
        this->b[Bangkok].color = Red;
        this->b[Beijing].color = Red;
        this->b[Bogota].color = Yellow;
        this->b[BuenosAires].color = Yellow;
        this->b[Cairo].color = Black;
        this->b[Chennai].color = Black;
        this->b[Chicago].color = Blue;
        this->b[Delhi].color = Black;
        this->b[Essen].color = Blue;
        this->b[HoChiMinhCity].color = Red;
        this->b[HongKong].color = Red;
        this->b[Istanbul].color = Black;
        this->b[Jakarta].color = Red;
        this->b[Johannesburg].color = Yellow;
        this->b[Karachi].color = Black;
        this->b[Khartoum].color = Yellow;
        this->b[Kinshasa].color = Yellow;
        this->b[Kolkata].color = Black;
        this->b[Lagos].color = Yellow;
        this->b[Lima].color = Yellow;
        this->b[London].color = Blue;
        this->b[LosAngeles].color = Yellow;
        this->b[Madrid].color = Blue;
        this->b[Manila].color = Red;
        this->b[MexicoCity].color = Yellow;
        this->b[Miami].color = Yellow;
        this->b[Milan].color = Blue;
        this->b[Montreal].color = Blue;
        this->b[Moscow].color = Black;
        this->b[Mumbai].color = Black;
        this->b[NewYork].color = Blue;
        this->b[Osaka].color = Red;
        this->b[Paris].color = Blue;
        this->b[Riyadh].color = Black;
        this->b[SanFrancisco].color = Blue;
        this->b[Santiago].color = Yellow;
        this->b[SaoPaulo].color = Yellow;
        this->b[Seoul].color = Red;
        this->b[Shanghai].color = Red;
        this->b[StPetersburg].color = Blue;
        this->b[Sydney].color = Red;
        this->b[Taipei].color = Red;
        this->b[Tehran].color = Black;
        this->b[Tokyo].color = Red;
        this->b[Washington].color = Blue;

        map<City,cityData>::iterator itr;

        for(itr = b.begin(); itr != b.end();++itr){
            itr->second.Cure = false;
            itr->second.diseaseLevel = 0;
            itr->second.ResearchStation = false;
        }

    }

    int& Board::operator[](const City city){
        return this->b[city].diseaseLevel;
    }

    //TODO - output format
    /*  |           <City>              |
        |*******************************| 
        | Neighbors:    <City1>         |
        |               <City2>         |
        |               <City3>         |
        | - - - - - - - - - - - - - - - |
        |Research station:  <bool>      |
        |Color :            <Color>     |
        |Has cure? :        <bool>      |
        |Disease level:     <int>       |
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */
    ostream& operator<<(ostream& os, Board &b){
        os<<boolalpha;
        for(auto& itr : b.b){
            os<<"|*******************************|"<<endl;
            os<<"|\t\t"+b.name[itr.first];
            int x = b.name[itr.first].size();
            if(x>7){os<<"\t|"<<endl;}
            else {os<<"\t\t|"<<endl;}
            os<<"|*******************************|"<<endl;
            os<<"|Neighbors:\t";
            vector<City>::iterator cityItr;
            for(auto& cityItr: itr.second.neighbors){
                os<<b.name[cityItr];
                int x = b.name[cityItr].size();
                if(x>7){ os<<"\t|\n|\t\t";}
                else {os<<"\t\t|\n|\t\t";}
            }
            os<<"\t\t|"<<endl;
            os<<"| - - - - - - - - - - - - - - - |"<<endl;
            os<<"|Reasearch station : \t"<<itr.second.ResearchStation<<"\t|"<<endl;
            os<<"|Color : \t\t"<<b.colors[itr.second.color]<<"\t|"<<endl;
            os<<"|Has cure? : \t\t"<<itr.second.Cure<<"\t|"<<endl;
            os<<"|Disease level : \t"<<itr.second.diseaseLevel<<"\t|"<<endl;
            os<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
            os<<"\n\n";
        }
        return os;
    }

    Board& Board::remove_cures(){
        for(auto &it : b){
            it.second.Cure = false;
        }
        return *this;
    }

    bool Board::is_clean(){
        for(auto &it : b){
            if(it.second.diseaseLevel > 0){
                return false;
            }
        }
        return true;
    }
}
