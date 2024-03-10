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
    void sCCutil(int u,vector<int>& disc,vector<int>& low,stack<int>& st,vector<bool> stackMember,int& time){
        disc[u] = ++time;
        low[u] = time;
        st.push(u);
        // cout << "time " << time << " " << u << endl;
        stackMember[u] = true;
        int n = adjList[u].size();
        // cout << n << endl;
        for(int i=0;i<n;i++){
            int adjVertex = adjList[u][i];
            if(disc[adjVertex] == -1){
                sCCutil(adjVertex,disc,low,st,stackMember,time);
                low[u] = min(low[u],low[adjVertex]);
            }else if(stackMember[adjVertex]==true){
                low[u] = min(low[u],low[adjVertex]);
            }
        }
        // cout << "HI" << st.size() << endl;
        int w;
        if(low[u] == disc[u]){
            while(st.top() != u){
                w = st.top();
                st.pop();
                cout << w <<" ";
                stackMember[w] = false;
            }
            w = st.top();
            st.pop();
            cout << w << endl;
            stackMember[w] = false;
        }
        return;
    }
    void stronglyConnectedComponets(){
        vector<int> discoveryTime = vector<int>(v,-1);
        vector<int> lowTime = vector<int>(v,-1);
        vector<bool> stackMember = vector<bool>(v,false);
        stack<int> st;
        int time = 0;
        for(int i=0;i<v;i++){
            if(discoveryTime[i]==-1){
                sCCutil(i,discoveryTime,lowTime,st,stackMember,time);
            }
        }
    }
};

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
        Graph graph(n);
        int number_of_vertices;
        cin >> number_of_vertices;
        for(int i=0;i<number_of_vertices;i++){
            int vertex,adjVertex;
            cin >> vertex >> adjVertex;
            graph.addEdge(vertex,adjVertex);
        }
        graph.stronglyConnectedComponets();
        cout << endl;
    }
    // cout << "\nSCCs in first graph \n";
    // Graph g1(5);
    // g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);
    // g1.addEdge(4, 3);
    // g1.stronglyConnectedComponets();
}