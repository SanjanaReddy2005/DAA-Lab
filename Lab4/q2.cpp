#include <iostream>
#include <vector>
using namespace std;

// time complexity is O(n) ans space complexity is O(n) in which two arrays are stored

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
        int p=0,q=0;
        int mid1 = 0,mid2 = 0;// for even tracking two numbers
        while(p+q<n+m){
            
            if(p==n || (q!=m && nums1[p]>=nums2[q])){
                if((p+q)==((n+m)/2-1)){
                    mid1=nums2[q];
                }else if(p+q==(n+m)/2){
                    mid2=nums2[q];
                    break;
                }
                q++;
            }else if(q==m || (p!=n && nums1[p]<nums2[q])){
                
                if((p+q)==((n+m)/2-1)){
                    mid1=nums1[p];
                }else if(p+q==(n+m)/2){
                    mid2=nums1[p];
                    break;
                }
                p++;
            }
            
        }
        if((n+m)%2==0){
            cout << (mid1+mid2)/2.0 << endl;
        }else{
            cout << mid2 << endl;
        }
    }
    
}