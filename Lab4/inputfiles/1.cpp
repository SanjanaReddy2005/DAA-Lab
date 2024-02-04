#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream input;
    input.open("../1.txt",ios::in);
    input << 10 << endl;
    input << 10000 << endl;
    for(int i=0;i<10000;i++){
        input << rand() << " ";
    }
    input << endl;
}