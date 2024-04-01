// the difference between q1 and q1e is here I am printing the values which are appended in the backpack
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
// the difference between q1 and q1e is here I am printing the values which are appended in the backpack
//greedy approch

// bool cmp(pair<double,pair<int,int> > a,pair<double,pair<int,int> > b){
//     if(a.first>b.first){
//         return true;
//     }else if(a.first==b.first){
//         if(a.second.first>b.second.first){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     return false;
// }

int max(int a,int b){
    return (a>b?a:b);
}

int knapsackGreedy(int n,int w[],int v[],int W){
    vector<pair<double,pair<int,int> > >  ratio;
    for(int i=0;i<n;i++){
        ratio.push_back(make_pair(double(v[i])/double(w[i]),make_pair(w[i],v[i])));
    }
    sort(ratio.begin(),ratio.end());
    int ans = 0;
    int weight = 0;
    for(int i=n-1;i>=0;i--){
        if(weight+ratio[i].second.first<=W){
            weight+=ratio[i].second.first;
            ans+=ratio[i].second.second;
        }
    }
    return ans;
}

// dunamic programing give the optimal solution

// dp approch

int knapsackDp(int n,int w[],int v[],int W){
    // vector<vector<int> > itemsPresent(n+1,vector<int>(w+1,0));
    vector<vector<int> > isPresent(n+1,vector<int>(W+1,0));
    // int isPresent[n+1][w+1];
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<W+1;i++){
        dp[0][i]= 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j>=w[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
                if(dp[i][j]==dp[i-1][j-w[i-1]]+v[i-1]){
                    isPresent[i][j] = true;
                }
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int k = n;
    int l = W;
    
    while(k > 0 && l > 0){
        if(isPresent[k][l]){
            // seq.push_back(k - 1);
            cout << k << " ";
            l -= w[k - 1];
        }
        k -= 1;
    }
    cout << endl;
    return dp[n][W];
}


int main(){
    // #ifndef ONLINE_JUDGE
	//     freopen("1.txt","r",stdin);
	//     freopen("1out.txt","w",stdout);
    // #endif
    int t;
    cin >> t;
    while(t--){
        int n,W;
        cin >> W >> n;
        int w[n],v[n];
        for(int i=0;i<n;i++){
            cin >> w[i];
        }
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int ans = knapsackGreedy(n,w,v,W);
        cout << "Greedy output is : " << ans << endl;
        int ansdp = knapsackDp(n,w,v,W);
        cout << "Dynamic Programing output is : " << ansdp << endl;
    }
}