#include <iostream>
#include <fstream>
using namespace std;
int N = 1e6;
// inplace sorting of two sorted arrays decreases space complexity to constant space

int main(){
    ofstream input;
    input.open("2.txt",ios::in);
    int testcases;
    testcases = rand()%10+1;
    input << testcases << endl;
    while(testcases--){
        int num1,num2;
        num1 =100000-rand()%(100000/2);
        num2 = 100000-num1;
        input << num1 << " " << num2 << endl;
        int prev = rand()%200;
        for(int i=0;i<num1+num2;i++){
            input << prev << " ";
            prev += rand()%200;
        }
        // prev = rand()%200;
        // for(int i=0;i<num2;i++){
        //     input << prev << " ";
        //     prev += rand()%200;
        // }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n+m];
        for(int i=0;i<n+m;i++){
            cin >> a[i];
        }
        int p=0,q=0;
        while(p<n || q<m){
            if(a[p]<a[n+q]){
                p++;
            }else if(a[p]>=a[n+q]){
                int key = a[n+q];
                int j = n+q-1;
                while(j>=p){
                    a[j+1] = a[j];
                    j--;
                }
                a[j+1] = key;
                q++;
                p++;
            }
        }
        for(int i=0;i<n+m;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}