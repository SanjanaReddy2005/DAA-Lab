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

class Graph{
    public:
    int v;
    vector<vector<int> > adjList;

    Graph(int number_of_vertices){
        v = number_of_vertices;
        adjList = vector<vector<int> >(v);
    }

    void addEdge(int vertex,int adjV){
        adjList[vertex].push_back(adjV);
        adjList[adjV].push_back(vertex);
    }

    void articulationPointsUtil(int u,vector<int>& disc,vector<int>& low,vector<bool>& visited,vector<bool>& isAp,int parent,int& time){
        disc[u] = ++time;
        low[u] = time;
        visited[u] = true;
        int children = 0;
        int n = adjList[u].size();
        for(int i=0;i<n;i++){
            if(!visited[adjList[u][i]]){
                children++;
                articulationPointsUtil(adjList[u][i],disc,low,visited,isAp,u,time);
                low[u] = min(low[u],low[adjList[u][i]]);
                if(parent!=-1 && low[adjList[u][i]]>=disc[u]){
                    isAp[u] = true;
                }
            }else if(adjList[u][i]!=parent){
                low[u] = min(low[u],disc[adjList[u][i]]);
            }
        }
        if(parent==-1 && children>=2){
            isAp[u] = true;
        }
    }

    void articulationPoints(){
        vector<int> discoveryTime(v,-1);
        vector<int> lowTime(v,-1);
        vector<bool> visited(v,false);
        vector<bool> isAP(v,false);
        int time = 0;
        int parent = -1;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                articulationPointsUtil(i,discoveryTime,lowTime,visited,isAP,parent,time);
            }
        }
        cout << "Articulation Points are " << endl;
        for(int i=0;i<v;i++){
            if(isAP[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void bridgeUtil(int u,vector<int>& disc,vector<int>& low,vector<bool>& visited,int parent,int& time){
        visited[u] = true;
        disc[u] = ++time;
        low[u] = time;
        int n = adjList[u].size();
        for(int i=0;i<n;i++){
            if(adjList[u][i]==parent){
                continue;
            }
            if(!visited[adjList[u][i]]){
                parent = u;
                bridgeUtil(adjList[u][i],disc,low,visited,parent,time);
                low[u] = min(low[u],low[adjList[u][i]]);
                if(low[adjList[u][i]]>disc[u]){
                    cout << adjList[u][i] << " " << u << endl;
                }
            }else{
                low[u] = min(low[u],disc[adjList[u][i]]);
            }
        }
    }

    void bridge(){
        vector<int> discvoryTime(v,-1);
        vector<int> lowTime(v,-1);
        vector<bool> visited(v,false);
        int parent = -1;
        int time = 0;
        cout << "Bridges of the graph " << endl;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bridgeUtil(i,discvoryTime,lowTime,visited,parent,time);
            }
        }

    }
};

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("5.txt","r",stdin);
	    freopen("5out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Graph graph(n);
        int number_of_edges;
        cin >> number_of_edges;
        for(int i=0;i<number_of_edges;i++){
            int vertex,adjVertex;
            cin >> vertex >> adjVertex;
            graph.addEdge(vertex,adjVertex);
        }
        graph.articulationPoints();
        graph.bridge();
        cout << endl;
    }
    // Graph g1(5);
    // g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);
    // g1.articulationPoints();
    // g1.bridge();
}