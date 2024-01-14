#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

class Graph{
    public:
    
    int noOfNodes;
    vector<vector<int> > adjacency_matrix;

    Graph(int value){
        noOfNodes=value;
        for(int i=0;i<noOfNodes;i++){
            vector<int> v(noOfNodes);
            adjacency_matrix.push_back(v);
        }
    }
    void update_weights(int i,int j,int weight){
        adjacency_matrix[i][j] = weight;
    }
    void update_weight_row(int i,vector<int> weights){
        adjacency_matrix[i] = weights;
    }
    void update_weight_mat(vector<vector<int> > weights){
        adjacency_matrix = weights;
    }
};
// long long fact(int n){
//     if(n==0 || n==1){
//         return 1;
//     }
//     return n*fact(n-1);
// }
//dp method
int travellingSalesman(int n,vector<vector<int> > adjacency_matrix, int start){
    vector<int> cities;
    for(int i=0;i<n;i++){
        if(i!=start){
            cities.push_back(i);
        }
    }
    int dmin = INT_MAX;//minimum distance
    do{
        int cdist = 0;//current distance
        int city = start;
        for(int i=0;i<n-1;i++){
            cdist += adjacency_matrix[city][cities[i]];
            city = cities[i];
        }
        cdist += adjacency_matrix[city][start];
        dmin = min(dmin,cdist);
    }while(next_permutation(cities.begin(),cities.end()));// time compleity O(n!){exponential time complexity}

    return dmin;
}
//second method
int travellingSalesman_tree(int n,vector<vector<int> >adjacency_matrix,vector<int> cities,int start){
    if(cities.size()==0){
        return adjacency_matrix[start][0];
    }
    int min = INT_MAX;
    for(int i=0;i<cities.size();i++){
        vector<int> next = cities;
        next.erase(next.begin()+i);
        int dist = adjacency_matrix[start][cities[i]]+travellingSalesman_tree(n-1,adjacency_matrix,next,cities[i]);
        if(min>dist){
            min = dist;
        }
    }
    return min;
}

int main(){
    ofstream input;
    input.open("3.txt",ios::in);
    int testcase;
    testcase = rand()%9+1;
    input << testcase << endl;
    while(testcase--){
        int num = rand()%10+1;
        input << num << endl;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(i==j) input << 0 << " " ;
                else input << rand()%10+1 << " ";
            }
            input << endl;
        }
    }
    #ifndef ONLINE_JUDGE
	    freopen("3.txt","r",stdin);
	    freopen("3out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;// no of nodes present in the graph
        Graph g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int value;
                cin >> value;
                g.update_weights(i,j,value);
            }
        }
        int start = 0;
        long long min_dist = travellingSalesman(n,g.adjacency_matrix,start);
       
        // vector<int> cities;
        // for(int i=1;i<n;i++){
        //     cities.push_back(i);
        // }
        // long long min_dist_tree = travellingSalesman_tree(n,g.adjacency_matrix,cities,start);
        cout << min_dist << endl;
    }

}