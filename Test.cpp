#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <vector>

TEST_CASE("empty board"){
    ariel::Board b1;
    //CHECK(b1.get_rownum==0);
    //CHECK(b1.get_colnum==0);
    CHECK_THROWS(b1.read(0,0,ariel::Direction::Horizontal,1));
}

TEST_CASE("bad - check of read") {
    ariel::Board b1;
    b1.post(0,0,ariel::Direction::Horizontal,"hi my name");
    b1.post(1,3,ariel::Direction::Horizontal,"is");
    b1.post(2,6,ariel::Direction::Vertical,"DAVID");
    /*
        hi my name
        ____is____
        ______D___
        ______A___
        ______V___
        ______I___
        ______D___
    */
    //CHECK(b1.get_rownum==6);
    //CHECK(b1.get_colnum==10);
    CHECK_THROWS(b1.read(0,0,ariel::Direction::Horizontal,0)); //length can not be 0.
    CHECK_THROWS(b1.read(8,0,ariel::Direction::Horizontal,3)); // row number out of range.
    CHECK_THROWS(b1.read(1,12,ariel::Direction::Vertical,3)); //col number out of range.
    CHECK_THROWS(b1.read(0,4,ariel::Direction::Horizontal,12)); // Horizontal length is not mach to the real length.
    CHECK_THROWS(b1.read(0,4,ariel::Direction::Vertical,9); //Vertical length is match to the real length.
    CHECK_THROWS(b1.read(6,4,ariel::Direction::Vertical,3); //Vertical length is geting out of range.
    CHECK_THROWS(b1.read(6,4,ariel::Direction::Horizontal,7); //Horizontal length is geting out of range.
}

TEST_CASE("check if the board grow"){
    ariel::Board b1;
    b1.post(0,0,ariel::Direction::Horizontal,"Hi");
    b1.post(8,15,ariel::Direction::Horizontal,"is");
    b1.post(23,47,ariel::Direction::Vertical,"me");
    CHECK(b1.read(8,40,ariel::Direction::Horizontal,3)=="___");
    CHECK(b1.read(0,47,ariel::Direction::Vertical,5)=="_____");
}

TEST_CASE("ost one on 2"){
    ariel::Board b1;
    b1.post(3,3,ariel::Direction::Horizontal,"BALAGAN");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BALAGAN");
    b1.post(3,4,ariel::Direction::Vertical,"xyz");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BxLAGAN");
    b1.post(3,7,ariel::Direction::Vertical,"bcd");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BxLAbAN");
    b1.post(3,6,ariel::Direction::Horizontal,"hi!");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BxLhi!N");
}

TEST_CASE("random post"){
    string str[]={"this","is","random","board"};
    ariel::Board b1;
    unsigned int r= rand() % 150;
    unsigned int c= rand() % 150;
    int strIndex = rand() % 4;
    
    for (size_t i = 0; i < 45; i++) {
        if(i%2==0){
            b1.post(r,c,ariel::Direction::Horizontal,str[strIndex]);
        }
        else{
            b1.post(r,c,ariel::Direction::Vertical,str[strIndex]);
 
        }
    }
    //b1.show();
}