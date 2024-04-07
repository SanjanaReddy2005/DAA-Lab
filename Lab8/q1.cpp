// C++ program for the above approach 
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

bool cmp(vector<int> a,vector<int> b){
	if(a[0]>=b[0]){
		return true;
	}
	return false;
}
// DSU data structure 
// path compression + rank by union 
class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	// Find function 
	int find(int i) 
	{ 
		if (parent[i] == -1) 
			return i; 

		return parent[i] = find(parent[i]); 
	} 

	// Union function 
	void unite(int x, int y) 
	{ 
		int set1 = find(x);
        int set2 = find(y);
        if(set1 != set2){
            if(rank[set1]>rank[set2]){
                parent[set2] = set1;
            }else{
                parent[set1] = set2;
            }
            rank[set1]+= rank[set2];
            rank[set2] = rank[set1];
        }
	} 
}; 

class Graph { 
	vector<vector<int> > edgelist; 
	int V; 

public: 
	Graph(int V) { this->V = V; } 

	void addEdge(int x, int y, int w) 
	{ 
        vector<int> v;
        v.push_back(w);
        v.push_back(x);
        v.push_back(y);
		edgelist.push_back(v); 
	} 

	void kruskals_mst() 
	{ 
		sort(edgelist.begin(), edgelist.end(),cmp); 
		DSU s(V); 
		int ans = 0; 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int x = edge[1]; 
			int y = edge[2]; 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 
			} 
		} 
		cout << "Maximum Cost Spanning Tree: " << ans << endl; 
	} 
}; 

int main() 
{ 
	// Graph g(5); 
	// g.addEdge(0, 3, 5); 
	// g.addEdge(0, 1, 1); 
	// g.addEdge(1, 2, 2); 
	// g.addEdge(1, 4, 4); 
	#ifndef ONLINE_JUDGE
	    freopen("1.txt","r",stdin);
	    freopen("1out.txt","w",stdout);
    #endif
	int t;
	cin >> t;
	while(t--){
		int V,E;
		cin >> V >> E;
		Graph g(V);
		for(int i=0;i<E;i++){
			int v1,v2,w;
			cin >> v1 >> v2 >> w;
			g.addEdge(v1,v2,w);
		}
		g.kruskals_mst();
	}
    // Graph g(4); 
    // g.addEdge(0, 1, 10); 
    // g.addEdge(1, 3, 15); 
    // g.addEdge(2, 3, 4); 
    // g.addEdge(2, 0, 6); 
    // g.addEdge(0, 3, 5); 

	// Function call 
	// g.kruskals_mst(); 
}
