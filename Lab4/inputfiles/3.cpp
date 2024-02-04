#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream input;
    input.open("../3.txt",ios::in);
    int t = 10;
    input << t << endl;
    while(t--){
        int n = 1000;
        int k = rand()%n;
        input << n << " " << k << endl;
        for(int i=0;i<n;i++){
            input << rand()%10000 << " ";
        }
        input << endl;
    }
}