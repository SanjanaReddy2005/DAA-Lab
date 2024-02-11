#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// timecomplexity is O(n^2) and spacComplexity is O(n^2)

bool isBipartitie(vector<vector<int> >& adj_mat,vector<int>& color_mat){
    int n = adj_mat.size();
    for(int i=0;i<n;i++){
        if(color_mat[i]==-1){
            queue<int> q;
            color_mat[i] = 1;
            q.push(i);
            while(!q.empty()){
                int c = q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(adj_mat[c][j]==1 && color_mat[j]==-1){
                        color_mat[j] = 1-color_mat[c];
                        q.push(j);
                    }else if(adj_mat[c][j]==1 && color_mat[j]==color_mat[c]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
};

bool canDivideintoClique(vector<vector<int> >& adj_mat){
    int n = adj_mat.size();
    vector<int>  color_mat(n,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                adj_mat[i][j] = 0;
                continue;
            }
            adj_mat[i][j] = !adj_mat[i][j];
        }
    }

    return isBipartitie(adj_mat,color_mat);
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("3.txt","r",stdin);
	    freopen("3out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > adj_mat;
        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                int k;
                cin >> k;
                row.push_back(k);
            }
            adj_mat.push_back(row);
        }
        cout << (canDivideintoClique(adj_mat)?"YES" : "NO") << endl;
    }
    
}