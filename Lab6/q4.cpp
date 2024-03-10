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
    }

    bool isCyclePresentutil(int u,vector<int>& predfs,vector<int>& postdfs,vector<bool>& visited,int& time){
        visited[u] = true;
        predfs[u] = ++time;
        int n = adjList[u].size();
        for(int i=0;i<n;i++){
            if(!visited[adjList[u][i]] && isCyclePresentutil(adjList[u][i],predfs,postdfs,visited,time)){
                return true;
            }else if(visited[adjList[u][i]] && postdfs[adjList[u][i]]==-1){
                return true;
            }
           
        }
        postdfs[u] = ++time;
        // cout << u << " "  << predfs[u] << " " << postdfs[u] << endl;
        return false;
    }

    bool isCyclePresent(){
        vector<int> predfs(v,-1),postdfs(v,-1);
        vector<bool> visited(v,0);
        int time = 0;
        for(int i=0;i<v;i++){
            if(!visited[i] && isCyclePresentutil(i,predfs,postdfs,visited,time)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("4.txt","r",stdin);
	    freopen("4out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int number_of_edges;
        cin >> number_of_edges;
        Graph graph(n);
        for(int i=0;i<number_of_edges;i++){
            int vertex,adjVertex;
            cin >> vertex >> adjVertex;
            graph.addEdge(vertex,adjVertex);
        }
        cout << (graph.isCyclePresent()?"Cycle":"Not a Cycle") << endl;
    }
    // // cout << "\nSCCs in first graph \n";
    // Graph g1(5);
    // g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);
    // g1.addEdge(4, 3);
    // cout << g1.isCyclePresent() << endl;

    // Graph g2(5);
    // g2.addEdge(0, 1);
    // g2.addEdge(0, 2);
    // g2.addEdge(2, 3);
    // g2.addEdge(3, 4);
    // g2.addEdge(4, 2);
    // // g2.addEdge(4, 3);
    // cout << g2.isCyclePresent() << endl;

    // Graph g3(5);
    // g3.addEdge(0, 1);
    // g3.addEdge(0, 2);
    // g3.addEdge(2, 3);
    // g3.addEdge(3, 4);
    // // g3.addEdge(4, 2);
    // // g3.addEdge(4, 3);
    // cout << g3.isCyclePresent() << endl;

}