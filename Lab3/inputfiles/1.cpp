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
        int m,n,q;
        m = rand()%10+1;
        n = rand()%10+1;
        q = rand()%10+1;
        input << m << " " << n << " " << n << " " << q << endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                input << rand()%10 << " ";
            }
            input << endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<q;j++){
                input << rand()%10 << " ";
            }
            input << endl;
        }
    }

}