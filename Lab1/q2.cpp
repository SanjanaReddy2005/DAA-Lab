#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}
// recursive method time complexity is O(2^n)
// int knapsack(int v[],int w[],int n,int W){
//     if(n==0||W==0){
//         return 0;
//     }
//     if(w[n-1]>W){
//         return knapsack(v,w,n-1,W);
//     }
//     return max(v[n-1]+knapsack(v,w,n-1,W-w[n-1]),knapsack(v,w,n-1,W));
// }
// dp method time complexity is O(n*W)
int knapsackdp(int v[],int w[],int n,int W){
    int mat[n+1][W+1];
    for(int i=0;i<n+1;i++){
        mat[i][0]=0;
    }
    for(int i=1;i<W+1;i++){
        mat[0][i] = 0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(j>=w[i])
           mat[i][j] = max(mat[i-1][j],mat[i-1][j-w[i-1]]+v[i-1]); 
           else
           mat[i][j]= mat[i-1][j];
        }
    }

    return mat[n][W];
}

int main(){
    ofstream input;
    input.open("2.txt",ios::in);
    int testcase;
    testcase = rand()%10+1;
    input << testcase << endl;
    while(testcase--){
        int num = rand()%10+1;
        input << num << endl;
        input << rand()%10+1 << endl;//W
        for(int i=0;i<num;i++){
            input << rand()%10+1 << " ";//v[i]
        }
        input << endl;
        for(int i=0;i<num;i++){
            input << rand()%10+1 << " ";//w[i]
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int v[n];
        int w[n];
        int W;
        cin >> W;
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        for(int i=0;i<n;i++){
            cin >> w[i];
        }
        // int ans = knapsack(v,w,n,W);
        int ansdp = knapsackdp(v,w,n,W);
        cout  << ansdp << endl;
    }
}