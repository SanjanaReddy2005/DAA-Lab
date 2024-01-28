#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream input;
    input.open("../2.txt",ios::in);
    int testcase;
    testcase = 10000;
    input << testcase << endl;
    while(testcase--){
        int n;
        n = 1000;
        input << n << endl;
        for(int i=0;i<n;i++){
            input << -50+rand()%200 << " ";
        }
        input << endl;
    }
}