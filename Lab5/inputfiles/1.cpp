#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream input;
    input.open("../1.txt",ios::in);
    int testcase;
    testcase = rand()%10+1;
    input << testcase << endl;
    while(testcase--){
        int n,m;
        n = 200;
        m = rand()%200;
        input << n << " " << m << endl;
        for(int i=0;i<n;i++){
            for(int i=0;i<m;i++){
                input << rand()%2 << " ";
            }
            input << endl;
        }
    }
}