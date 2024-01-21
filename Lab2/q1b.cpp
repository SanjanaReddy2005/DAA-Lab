#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int N = 1e6;

// union is in O(n);

int main(){
     ofstream input;
    input.open("1b.txt",ios::in);
    int testcases;
    testcases = rand()%10+1;
    input << testcases << endl;
    while(testcases--){
        int num1,num2;
        num1 =rand()%100000+1;
        num2 = rand()%100000+1;
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
	    freopen("1b.txt","r",stdin);
	    freopen("1bout.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n],b[m];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<m;i++){
            cin >> b[i];
        }
        vector<int> union_set;
        int p=0,q=0;
        while((p+q)<(n+m)){
            while(p<n-1 && a[p]==a[p+1]){
                p++;
            }
            while(q<m-1 && b[q]==b[q+1]){
                q++;
            }
            if(p==n || (q!=m && a[p]>b[q])){
                union_set.push_back(b[q]);
                q++;
            }else if(q==m || (p!=n && a[p]<b[q])){
                union_set.push_back(a[p]);
                p++;
            }else if(a[p]==b[q]){
                union_set.push_back(a[p]);
                p++;
                q++;
            }
        }
        for(auto nums: union_set){
            cout << nums << " ";
        }
        cout << endl;

    }
}