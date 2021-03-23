#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <vector>

TEST_CASE("empty board"){
    ariel::Board b1;
    CHECK_THROWS(b1.read(0,0,ariel::Direction::Horizontal,1));
}

TEST_CASE("bad check of read") {
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
    CHECK_THROWS(b1.read(0,0,ariel::Direction::Horizontal,0)); //length can not be 0.
    CHECK_THROWS(b1.read(8,0,ariel::Direction::Horizontal,3)); // row number out of range.
    CHECK_THROWS(b1.read(1,12,ariel::Direction::Vertical,3)); //col number out of range.
    CHECK_THROWS(b1.read(0,4,ariel::Direction::Horizontal,12)); // Horizontal length is not mach to the real length.
    CHECK_THROWS(b1.read(0,4,ariel::Direction::Vertical,9)); //Vertical length is match to the real length.
    CHECK_THROWS(b1.read(6,4,ariel::Direction::Vertical,3)); //Vertical length is geting out of range.
    CHECK_THROWS(b1.read(6,4,ariel::Direction::Horizontal,7)); //Horizontal length is geting out of range.
}

TEST_CASE("check if all the board grow"){
    ariel::Board b1;
    b1.post(0,0,ariel::Direction::Horizontal,"Hi");
    b1.post(8,15,ariel::Direction::Horizontal,"is");
    b1.post(23,47,ariel::Direction::Vertical,"me");
    CHECK(b1.read(8,40,ariel::Direction::Horizontal,3)=="___");
    CHECK(b1.read(0,47,ariel::Direction::Vertical,5)=="_____");
}

TEST_CASE("post one on 2"){
    ariel::Board b1;
    b1.post(3,3,ariel::Direction::Horizontal,"BALAGAN");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BALAGAN");
    b1.post(3,4,ariel::Direction::Vertical,"xyz");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BxLAGAN");
    b1.post(3,7,ariel::Direction::Vertical,"bcd");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BxLAbAN");
    b1.post(3,6,ariel::Direction::Horizontal,"hi!");
    CHECK(b1.read(3,3,ariel::Direction::Horizontal,7)=="BxLhi!N");
    CHECK(b1.read(4,4,ariel::Direction::Horizontal,4)== "y__c");
    b1.post(4,0,ariel::Direction::Horizontal,"this is very very very long string");
    CHECK(b1.read(4,4,ariel::Direction::Horizontal,4)== " is ");


}

TEST_CASE("random post"){
    string str[]={"this","is","random","board"};
    ariel::Board b1;
    
    for (size_t i = 0; i < 100; i++) {
        unsigned int r= rand() % 1550;
        unsigned int c= rand() % 1550;
        int strIndex = rand() % 4;
    
        if(i%2==0){
            CHECK_NOTHROW(b1.post(r,c,ariel::Direction::Horizontal,str[strIndex]));
            }
        else{
            CHECK_NOTHROW(b1.post(r,c,ariel::Direction::Vertical,str[strIndex]));
 
        }
        cout<< "row: "<<r <<" col: " << c <<endl;
    }
    //b1.show();
}
