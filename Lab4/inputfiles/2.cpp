#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream input;
    input.open("../2.txt",ios::in);
    int t = 10;
    input << t << endl;
    while(t--){
        int n = 1000;
        int m = 1000;
        input << n << " " << m << endl;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans +=rand()%25;
            input << ans << " ";
        }
        input << endl;
        ans = 0;
        for(int i=0;i<m;i++){
            ans +=rand()%25;
            input << ans << " ";
        }
        input << endl ;
    }
}