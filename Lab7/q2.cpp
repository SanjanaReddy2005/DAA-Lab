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

struct jobProfit{
    bool operator()(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b){
        return a.second.first < b.second.first;
    }

};

 bool cmp(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b){
    if(a.second.first>=b.second.first){
        return true;
    }
    return false;
}




int jobSeqGreedy(vector<pair<int,pair<int,int> > > job,int n,vector<int>& jobDone){
    sort(job.begin(),job.end(),cmp);
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=min(n-1,job[i].second.second-1);j>=0;j--){
            // cout << j << endl;
            if(jobDone[j]==-1){
                jobDone[j] = job[i].first;
                res += job[i].second.first;
                break;
            }
        }
    }
    
    return res;
};

bool jobDeadlinecmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return a.second.second < b.second.second;
}

int jobSeqPriority(vector<pair<int,pair<int,int> > >job,int n){
    sort(job.begin(),job.end(),jobDeadlinecmp);
    vector<pair<int,pair<int,int> > > res;
    int ans = 0;
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,jobProfit > jobmaxHeap;
    for(int i=n-1;i>=0;i--){
        int slotAvailable;
        if(i==0){
            slotAvailable = job[i].second.second;
        }else{
            slotAvailable = job[i].second.second - job[i-1].second.second;
        }
        jobmaxHeap.push(job[i]);
        while(slotAvailable>0 && !jobmaxHeap.empty()){
            pair<int,pair<int,int> > job_info = jobmaxHeap.top();
            // cout << jobmaxHeap.size() << " " << job_info.second.first << endl;
            jobmaxHeap.pop();
            slotAvailable--;
            res.push_back(job_info);
            ans+=job_info.second.first;
        }
    }
    // for(int i=0;i<res.size();i++){
    //     cout << res[i].first << " " << res[i].second.first << " " << res[i].second.second << endl;
    // }
    return ans;
}

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
        vector<pair<int,pair<int,int> > >job;
        for(int i=0;i<n;i++){
            int deadLine, profit;
            cin >> deadLine >> profit;
            job.push_back(make_pair(i,make_pair(profit,deadLine)));
        }
        vector<int> jobDone(n,-1);
        int profitGreedy = jobSeqGreedy(job,n,jobDone);
        cout << "Profit objtained by greedy method is : " << profitGreedy << endl;
        int profitPriorityQueue = jobSeqPriority(job,n);
        cout << "Profit obtained by priority queue is : " << profitPriorityQueue << endl;
    }
}