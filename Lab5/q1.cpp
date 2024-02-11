#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// using bfs and implemented for finding out maximum region in the matrix
// time complexity is O(n^2) and space compleity is O(n^2)->visited array

int bfs(vector<vector<int> > mat,vector<vector<int> >& visited,int startrow,int startcol){// apprximatly 9*n^2 compelxity for bfs
    int count = 1;
    queue<pair<int,int> > q;
    int n = mat.size();
    int m = mat[0].size();
    q.push(make_pair(startrow,startcol));
    visited[startrow][startcol] = 1;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int row = p.first;
        int col = p.second;
        for(int i=row-1;i<=row+1;i++){
            for(int j=col-1;j<=col+1;j++){
                if(i>=0 && i<n && j>=0 && j<m && visited[i][j]==0 && mat[i][j]==1){
                    visited[i][j] = 1;
                    count++;
                    q.push(make_pair(i,j));
                }
            }
        }
        
    }
    return count;
}

int maxRegion(vector<vector<int> > mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int> > visited(n,vector<int>(m,0));
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1 && visited[i][j]==0){
                int count = bfs(mat,visited,i,j);
                if(max<count) max = count;
            }
        }
    }
    return max;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("1.txt","r",stdin);
	    freopen("1out.txt","w",stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int> > mat;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                int k;
                cin >> k;
                v.push_back(k);
            }
            mat.push_back(v);
        }
        int max = maxRegion(mat);
        cout << max << endl;
    }
    
}