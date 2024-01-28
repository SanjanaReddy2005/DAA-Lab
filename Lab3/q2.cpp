#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

// This is divide and conquer apporoch

int max(int a,int b,int c){
    return (a>(b>c?b:c)?a:(b>c?b:c));
}

int maxSum(int a[],int l,int r){
    if(l>r) return INT_MIN;
    if(l==r) return a[l];
    int m = l+(r-l)/2;
    int sum = 0;
    int leftSum = 0;
    int rightSum = 0;
    for(int i=m-1;i>=l;i--){
        sum+=a[i];
        if(sum> leftSum){
            leftSum = sum;
        }
    }
    sum = 0;
    for(int i=m+1;i<=r;i++){
        sum+=a[i];
        if(sum>rightSum){
            rightSum = sum;
        }
    }
    return max(maxSum(a,l,m-1),maxSum(a,m+1,r),leftSum+rightSum+a[m]);
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int sum = maxSum(a,0,n-1);
        cout << "Max Sum: " << sum << endl;
    }
}