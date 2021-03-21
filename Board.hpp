 #include <vector>
 #include<iostream>

 using namespace std;
 
 namespace ariel{
    class Board{
        private:
            vector<vector<char>> board;
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
    };
 }