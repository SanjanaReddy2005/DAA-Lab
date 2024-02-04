#include <iostream>
#include <vector>
using namespace std;

// time complexity for best case is O(n) worst complexity is O(n^2)

int partion(int a[],int l,int r){
    int pivot = a[r];
    int i =l;
    int j = l;
    while(j<=r){
        if(a[j]<pivot){
            swap(a[j],a[i]);
            i++;
        }
        j++;
    }
    swap(a[i],a[r]);
    return i;
}

int kth_largest(int a[],int k,int l,int r,int n){
    if(l>=r) return a[l];
    int i = partion(a,l,r);
    if(i>n-k){
       return kth_largest(a,k,l,i-1,n);
    }
    if(i<n-k){
        return kth_largest(a,k,i+1,r,n);
    }
    return a[i];
}

int main(){
     #ifndef ONLINE_JUDGE
	    freopen("3.txt","r",stdin);
	    freopen("3out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int nums[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int ans = kth_largest(nums,k,0,n-1,n);
        cout << ans << endl;
    }
}