#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//time complexity is linear O(n)
long long max_sum(int a[],int n){
    int max = INT_MIN;
    int second_max = max;
    for(int i=0;i<n;i++){
        if(max <= a[i]){
            second_max = max;
            max = a[i];
        }else if(second_max<a[i]){
            second_max = a[i];
        }
    }
    return max+second_max;
}

int main(){
    ofstream input;
    input.open("1.txt",ios::in);
    int testcase;
    testcase = rand()%10+1;
    input << testcase << endl;
    while(testcase--){
        int num = rand()%20+1;
        input << num << endl;
        for(int i=0;i<num;i++){
            input << rand()%10+1 << " ";
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("1.txt","r",stdin);
	    freopen("1out.txt","w",stdout);
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

        int sum = max_sum(a,n);
        cout << sum <<endl;
    }

}