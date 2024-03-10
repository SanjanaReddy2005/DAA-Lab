#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long

class Graph{
    public:
    int v;
    vector<vector<int> > adj_list;

    Graph(int number_of_vertices){
        v = number_of_vertices;
        vector<vector<int> > vec(v);
        adj_list = vec;
    }

    void addEdge(int vertex,int adjv){
        adj_list[vertex].push_back(adjv);
    }

    void topologicalSortUtil(int u,vector<bool>& visited,stack<int>& s){
        visited[u] = true;
        int n = adj_list[u].size();
        for(int i=0;i<n;i++){
            if(visited[adj_list[u][i]]==false){
                topologicalSortUtil(adj_list[u][i],visited,s);
            }
        }
        s.push(u);
    }

    void topologicalSort(){
        stack<int> s;
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                topologicalSortUtil(i,visited,s);
            }
        }
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main(){
     #ifndef ONLINE_JUDGE
	    freopen("1.txt","r",stdin);
	    freopen("1out.txt","w",stdout);
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
        // Graph graph(6);
        // graph.addEdge(5,0);
        // graph.addEdge(5,2);
        // graph.addEdge(4,0);
        // graph.addEdge(4,1);
        // graph.addEdge(2,3);
        // graph.addEdge(3,1);
        // graph.topologicalSort();
    }
}