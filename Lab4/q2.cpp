#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

// space complexity is O(1) ans time complexity is O(log(min(n,m))) in which two arrays are stored

int max(int a,int b){
    return (a>b?a:b);
}
int min(int a,int b){
    return (a>=b?b:a);
}

double Median(int a[],int b[],int n,int m){
    if(n>m){
        return Median(b,a,m,n);
    }
    int combinedMid = (n+m+1)/2;
    int l = 0;
    int r = n;
    while(l<=r){
        int mid = l+(r-l)/2;
        int asize = mid;
        int bsize = combinedMid - mid;
        int lefta = (asize>0?a[asize-1]:INT_MIN);
        int righta = (asize<n?a[asize]:INT_MAX);
        int leftb = (bsize>0?b[bsize-1]:INT_MIN);
        int rightb = (bsize<n?b[bsize]:INT_MAX);
        if(lefta<=rightb && leftb<=righta){
            if((n+m)%2==0){
                return (max(lefta,leftb)+min(righta,rightb))/2.0;
            }else{
                return max(lefta,leftb);
            }
        }else if(lefta>rightb){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return 0;
}

int main(){
     #ifndef ONLINE_JUDGE
	    freopen("2.txt","r",stdin);
	    freopen("2out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int nums1[n],nums2[m];
        for(int i=0;i<n;i++){
            cin >> nums1[i];
        }
        for(int i=0;i<m;i++){
            cin >> nums2[i];
        }
        cout << Median(nums1,nums2,n,m) << endl;
        
    }
    
}