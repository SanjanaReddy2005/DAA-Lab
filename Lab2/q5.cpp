#include <iostream>
#include <cmath>
#include <climits>
#include <math.h>
#include <fstream>
using namespace std;

void minima(int a[],int n){
    int min1 = INT_MAX,min2 = INT_MAX;
    for(int i=0;i<n;i++){ //O(n*c)
        if(min1>=a[i]){
            min2 = min1;
            min1 = a[i];
        }else if(a[i]<min2){
            min2 = a[i];
        }
    }
    cout << "First minimum : " << min1 << " Second minimum : " << min2 << endl;
    return;
}
// time complexity is O(n) in one loop we can find first minimum and second minimum
int main(){
    ofstream input;
    input.open("5.txt",ios::in);
    int testcase;
    testcase = 1;
    input << testcase << endl;
    while(testcase--){
        int num = 10000;
        input << num << endl;
        int prev = rand()%200;
        for(int i=0;i<num;i++){
            input << prev << " ";
            prev+=rand()%200;
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("5.txt","r",stdin);
	    freopen("5out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        minima(a,n);
    }

}