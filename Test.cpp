/**
 * Test to check Number with units exam.
 * cpp course.
 *
 * AUTHORS: Yosef Schwartz.
 * 
 * Date: 02 on may 2021.
 */
#include <iostream>
#include <string>

#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"

#include "Medic.hpp"
#include "FieldDoctor.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "GeneSplicer.hpp"


using namespace pandemic;
using namespace std;

/*
Check that test can create all types of roles
*/
Board b = Board();

TEST_CASE("Create roles") {
    CHECK_NOTHROW(Player p(b,Algiers));
    CHECK_NOTHROW(OperationsExpert opeExp(b,Baghdad));
    CHECK_NOTHROW(Dispatcher dis(b,Chicago));
    CHECK_NOTHROW(FieldDoctor dieDoc(b,Delhi));
    CHECK_NOTHROW(Researcher res(b,Essen));
    CHECK_NOTHROW(Medic med(b,Tehran));
    CHECK_NOTHROW(Virologist vir(b,Riyadh));
    CHECK_NOTHROW(GeneSplicer genSpl(b,Istanbul));
    CHECK_NOTHROW(Scientist sci(b,SaoPaulo,5));
}

TEST_CASE("functions of Player"){
    Player p (b,Istanbul);
    CHECK_NOTHROW(p.drive(Milan));
    CHECK_NOTHROW(p.drive(Essen));
    p.take_card(Moscow);
    CHECK_THROWS(p.drive(Moscow));
    CHECK_NOTHROW(p.fly_direct(Moscow));
    p.take_card(Moscow);
    CHECK_NOTHROW(p.fly_charter(Mumbai));
    p.take_card(Moscow);
    CHECK_NOTHROW(p.build());
    //Check again, now the player doesn't have the correct card,
    //but because the research station already exist, it's shouldn't throe exception
    CHECK_NOTHROW(p.build());
    CHECK_NOTHROW(p.drive(Tehran));
    CHECK_THROWS(p.build());
    CHECK_NOTHROW(p.drive(Moscow));
    p.take_card(Moscow);
    CHECK_NOTHROW(p.build());
    CHECK_NOTHROW(p.fly_charter(Kolkata));
    p.take_card(Kolkata);
    CHECK_NOTHROW(p.build());
    CHECK_NOTHROW(p.fly_shuttle(Moscow));
    CHECK_THROWS(p.fly_shuttle(Manila));
    //Collect 4 black cards
    p.take_card(Tehran).take_card(Delhi).take_card(Chennai).take_card(Kolkata);
    CHECK_THROWS(p.discover_cure(Black));
    //Collect the 5
    p.take_card(Mumbai);
    CHECK_NOTHROW(p.discover_cure(Black));
    //Try to discover cure again to same color, although the player
    //doesn't have 5 cards of this color, the methods shouldn't throw an exception
    CHECK_NOTHROW(p.discover_cure(Black));
    p.take_card(Moscow);
    CHECK_NOTHROW(p.fly_direct(Lagos));
    CHECK_NOTHROW(b.b[Lagos] = 2);
    CHECK_NOTHROW(p.treat(Lagos));
    CHECK_NOTHROW(p.treat(Lagos));
    CHECK_THROWS(p.treat(Lagos));
    p.take_card(Moscow);
    CHECK_NOTHROW(p.fly_direct(Moscow));
    CHECK_NOTHROW(b.b[Moscow] = 4);
    CHECK_NOTHROW(p.treat(Moscow));
    CHECK_THROWS(p.treat(Moscow));
}

TEST_CASE("Special functions of each role"){
    b.remove_cures();
    Player p(b,Algiers);
    OperationsExpert opeExp(b,Baghdad);
    /*
    Operation Expert can build research station withou throw associated card.
    */
    CHECK_NOTHROW(opeExp.build());
    CHECK_THROWS(p.build());

    /*
    Dispatcher can "fly_direct" without throw asssociated card,
    if he at city that had research station.
    */
    Dispatcher dis(b,Algiers);
    dis.take_card(Algiers).build();
    CHECK_NOTHROW(dis.fly_direct(Bogota));
    CHECK_THROWS(p.fly_direct(Bogota));

    /*
    Scientist can "discover_cure" with N cards, the N pass with the cunstructor. 
    */
    Scientist sci(b,SaoPaulo,2);
    p.take_card(SaoPaulo).fly_direct(SaoPaulo);
    sci.take_card(London).take_card(Essen);
    p.take_card(London).take_card(Essen);
    sci.take_card(SaoPaulo).build();
    CHECK_NOTHROW(sci.discover_cure(Blue));
    CHECK_THROWS(p.discover_cure(Blue));

    /*
    Reasearcher can "Discover_cure" anywhere, even if research station don't exist at this city.
    */
    Researcher res(b, Lima);
    res.take_card(LosAngeles).take_card(Miami).take_card(MexicoCity).take_card(SaoPaulo).take_card(BuenosAires);
    p.take_card(Lima).fly_direct(Lima);
    p.take_card(LosAngeles).take_card(Miami).take_card(MexicoCity).take_card(SaoPaulo).take_card(BuenosAires);
    CHECK_THROWS(p.discover_cure(Yellow));
    CHECK_NOTHROW(p.discover_cure(Yellow));

    /*
    When medic "treat" all disease cube removed, not just one.
    Also, if the cure to color of current city was dicovered, all disease cube removed automatically.
    */
   //Treat to 0 without cure
   Medic med(b, Taipei);
   p.take_card(Taipei).fly_direct(Taipei);
   med.take_card(Taipei).build();
   b[Taipei] = 4;
   med.treat(Taipei);
   CHECK_EQ(b[Taipei],4);
   b[Taipei] = 4;
   p.treat(Taipei);
   CHECK_NE(b[Taipei],4);

   //Check that disease level decrease to zero when medic arrived to city
   b[Manila] = 4;
   med.take_card(Beijing).take_card(Seoul).take_card(Tokyo).take_card(Osaka).take_card(HongKong);
   med.discover_cure(Red);
   med.take_card(Manila).fly_direct(Manila);
   CHECK_EQ(b[Manila],0);
   med.drive(Sydney);
   b[Manila] = 4;
   p.take_card(Manila).fly_direct(Manila);
   CHECK_NE(b[Manila],0);
   p.treat(Manila);
   CHECK_EQ(b[Manila],0);

   /*
    Virologist can treat from anywhere by throw associated card.
   */
    Virologist vir(b,SanFrancisco);
    p.take_card(SanFrancisco).fly_direct(SanFrancisco);
    vir.take_card(LosAngeles);
    b[LosAngeles] = 3;
    CHECK_NOTHROW(vir.treat(LosAngeles));
    CHECK_EQ(b[LosAngeles],2);
    p.take_card(LosAngeles);
    CHECK_THROWS(p.treat(LosAngeles));

    /*
    Gene Splicer can "discover cure" with 5 cards even not same color
    */
    GeneSplicer genS(b, NewYork);
    genS.take_card(NewYork).build();
    genS.take_card(MexicoCity).take_card(Madrid).take_card(Shanghai).take_card(Montreal).take_card(Algiers);
    CHECK_NOTHROW(genS.discover_cure(Red));

    /*
    Field doctor can treat current city, and all connected cities without throw card.
    */
    FieldDoctor dieDoc(b,Delhi);
    p.take_card(Delhi).fly_direct(Delhi);
    b[Karachi] = 3;
    CHECK_NOTHROW(dieDoc.treat(Karachi));
    CHECK_EQ(b[Karachi],2);
    p.take_card(Karachi);
    CHECK_THROWS(p.treat(Karachi));
    CHECK_NE(b[Karachi],1);
}

