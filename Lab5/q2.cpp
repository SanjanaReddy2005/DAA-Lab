#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//time complexity is O(N) space complexity is O(N)

int minNumberOfMoves(vector<int> game,int n){
    vector<bool> visited(n,false);
    queue<pair<int,int> > q;
    visited[0] = true;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> p = q.front();
        int vertex = p.first;
        int turn = p.second;
        if(vertex==n-1) break;
        q.pop();
        for(int i=vertex+1;i<=vertex+6;i++){
            if(visited[i]==false){
                visited[i] = true;
                int pos = (game[i]==-1?i:game[i]);
                q.push(make_pair(pos,turn+1));
            }
        }
    }
    return q.front().second;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2out.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<int> game(n,-1);
    int ladersNumber ;
    cin >> ladersNumber ;
    for(int i=0;i<ladersNumber;i++){
        int laderInitialpos,laderFinalPos;
        cin >> laderInitialpos >> laderFinalPos;
        game[laderInitialpos] = laderFinalPos;
    }
    int snakesNumber;
    cin >> snakesNumber;
    for(int i=0;i<snakesNumber;i++){
        int snakeInitialPos,snakeFinalPos;
        cin >> snakeInitialPos >> snakeFinalPos ;
        game[snakeInitialPos] = snakeFinalPos;
    }
    cout << minNumberOfMoves(game,n) << endl;
}