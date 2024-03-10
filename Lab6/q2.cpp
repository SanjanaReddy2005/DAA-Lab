#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Graph{
    public:
    int v;
    vector<vector<int> > adj_list;
    Graph(int number_of_vertices){
        v = number_of_vertices;
        adj_list = vector<vector<int> >(v);
    }
    void addEdge(int vertex,int adjV){
        adj_list[vertex].push_back(adjV);
    }
    void topologicalSort(){
        vector<int> inDegree(v,0);
        vector<int> dist(v,0);
        for(int i=0;i<v;i++){
            int n = adj_list[i].size();
            for(int j=0;j<n;j++){
                inDegree[adj_list[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(inDegree[i]==0){
                q.push(i);
                dist[i]++;
            }
        }
        vector<int> topologicalOrder;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topologicalOrder.push_back(u);

            int n = adj_list[u].size();

            for(int i=0;i<n;i++){
                inDegree[adj_list[u][i]]--;
                dist[adj_list[u][i]] = max(dist[adj_list[u][i]],dist[u]+1);
                if(inDegree[adj_list[u][i]]==0){
                    q.push(adj_list[u][i]);
                }
            }

        }
        for(int i=0;i<topologicalOrder.size();i++){
            cout << topologicalOrder[i] << " ";
        }
        cout << endl;
        int maxDist = 0;
        for(int i=0;i<v;i++){
            cout << dist[i] << " ";
            if(maxDist<dist[i]){
                maxDist = dist[i];
            }
        }
        cout << endl;
        cout << "Maximum length path exists in graph is " << maxDist << endl;
    }
};

int main(){
     #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2out.txt","w",stdout);
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
        graph.topologicalSort();
    }
    // Graph graph(6);
    // graph.addEdge(5,0);
    // graph.addEdge(5,2);
    // graph.addEdge(4,0);
    // graph.addEdge(4,1);
    // graph.addEdge(2,3);
    // graph.addEdge(3,1);
    // graph.topologicalSort();
}