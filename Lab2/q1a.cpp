#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int N = 1e6;

// sorting two sorted arrrays in O(n)

int main(){
    ofstream input;
    input.open("1a.txt",ios::in);
    int testcases;
    testcases = rand()%10+1;
    input << testcases << endl;
    while(testcases--){
        int num1,num2;
        num1 =rand()%N;
        num2 = rand()%N;
        input << num1 << " " << num2 << endl;
        int prev = rand()%200;
        for(int i=0;i<num1;i++){
            input << prev << " ";
            prev += rand()%200;
        }
        prev = rand()%200;
        input << endl;
        for(int i=0;i<num2;i++){
            input << prev << " ";
            prev += rand()%200;
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("1a.txt","r",stdin);
	    freopen("1aout.txt","w",stdout);
    #endif
    long t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n ;
        // int a[m],b[n],c[m+n];
        vector<int> a(m),b(n),c(m+n);
        for(int i=0;i<m;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        int p =0,q=0;
        while((p+q)<(m+n)){
            if( (p==m ) ||(q!=n && a[p]>b[q])){
                c[p+q] = b[q];
                q++;
                
            }else if((q==n ) || (a[p]<=b[q]&& p!=m)){
                c[p+q]=a[p];
                p++;
            }
            
        }
        for(int i=0;i<(m+n);i++){
            cout << c[i] << " ";
        }
        cout << endl;
    }
}