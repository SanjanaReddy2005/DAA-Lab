#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// implemented merger sort for finding number of inversion in the array
// time complexity is O(nlog(n)) 
// space complexity is O(n)

int merge(int a[],int temp[],int l,int mid,int r){
    int start1 = l;
    int start2 = mid;
    int start = l;
    int count = 0;
    while((start1<mid) && (start2<=r)){
        if(a[start1]<a[start2]){
            temp[start++] = a[start1++];
        }else{
            temp[start++] = a[start2++];
            count+= mid-start1; //a[j] is making mid-start1 inversion forward
        }
    }
    while(start1<mid){
        temp[start] = a[start1];
        start++;
        start1++;
    }
    while(start2<mid){
        temp[start] = a[start2];
        start++;
        start2++;
    }
    for(int i=l;i<=r;i++){
        a[i]=temp[i];
    }
    return count;
}

int mergesort(int a[],int temp[],int l,int r){
    if(l>=r) return 0;
    int mid = l+(r-l)/2;
    int count = 0;
    count+=mergesort(a,temp,l,mid);
    count+=mergesort(a,temp,mid+1,r);
    count+=merge(a,temp,l,mid+1,r);
    return count;
}

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
        int a[n],temp[n]; // O(n) space complexity;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        long long count = mergesort(a,temp,0,n-1);
        cout << count << endl;
    }
}