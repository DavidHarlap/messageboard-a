 #include <vector>
 #include<iostream>
 #include "Direction.hpp"


 using namespace std;
 
 namespace ariel{
    class Board{
        private:
            vector<vector<char>> board;
            unsigned int rownum=0;
            unsigned int colnum=0;
        public:
            void post(unsigned int row,unsigned int column,ariel::Direction dir,string str);
            string read(unsigned int row,unsigned int column,ariel::Direction dir,unsigned int length);
            
            void show(){
                for(vector<char> temp : board){
                    for(char ch : temp){
                        cout<< ch;
                    }
                    cout<< endl;
                }
            }
            unsigned int get_rownum() {return rownum;}
            unsigned int get_colnum() {return colnum;}

    };
 }