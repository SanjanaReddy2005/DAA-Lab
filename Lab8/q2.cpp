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

//O(2^n*(n+m)) is the time complexity

long long minCost(int n, int m, int mask, int prev, int col,vector<vector<vector<int> > >& graph,vector<vector<vector<int> > >& dp)
{
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if (dp[mask][prev][col == 1] != 0) {
        return dp[mask][prev][col == 1];
    }
 
    long long ans = 1e9;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (graph[prev][i][j] && !(mask & (1 << i)) 
                && (j != col)) {
                long long z = graph[prev][i][j] + 
                              minCost(n,m,mask|(1<<i),i,j,graph,dp);
                ans = min(z, ans);
            }
        }
    }
    return dp[mask][prev][col==1] = ans;
}

int getGraphCost(vector<pair<pair<int,int> ,pair<int,char> > >& g,int m,int n){
    vector<vector<vector<int> > > graph(n,vector<vector<int> >(n,vector<int>(2)));
    for(int i=0;i<m;i++){
        graph[g[i].first.first][g[i].first.second][g[i].second.second == 'G'] = g[i].second.first;
    }
    vector<vector<vector<int> > > dp((1<<n),vector<vector<int> >(n,vector<int> (2)));
    long long ans = 1e9;
 
    for (int i = 0; i < n; i++) {
        ans = min(ans, minCost(n, m, 1 << i, i, 2,graph,dp));
    }
 
    if (ans != 1e9) {
        return ans;
    }
    else {
        return -1;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<pair<int,int> , pair<int,char> > > g ;
        for(int i=0;i<m;i++){
            int v1,v2,w;
            char col;
            cin >> v1 >> v2 >> w >> col;
            g.push_back(make_pair(make_pair(v1,v2),make_pair(w,col)));
        }
        cout << getGraphCost(g,m,n) << endl;
    }
    // int n = 3,m = 4;
    // vector<pair<pair<int,int> , pair<int,char> > > g ;
    // g.push_back(make_pair(make_pair(1,2),make_pair(2,'B')));
    // g.push_back(make_pair(make_pair(1,2),make_pair(3,'G')));
    // g.push_back(make_pair(make_pair(2,3),make_pair(4,'G')));
    // g.push_back(make_pair(make_pair(2,3),make_pair(5,'B')));
    // cout << getGraphCost(g,m,n) << '\n';
}