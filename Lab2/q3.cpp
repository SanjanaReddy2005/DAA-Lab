#include <iostream>
#include <fstream>
using namespace std;
// to sorting inplace in merge sort we have to shift the array toward right similar to insertion sort 
// time complexity is O(n^2logn) but sorting is done inplace.

void merge(int a[],int left,int mid,int right){
    int left2 = mid+1;
    if(a[mid] <a[left2]){
        return;
    }
    
    while(left<=mid && left2<=right){
        if(a[left] <a[left2]){
            left++;
        }else{
            int key = a[left2];
            int j = left2-1;
            while(j>=left){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = key;
            left++;
            mid++;
            left2++;
        }
    }
}

void mergeSortit(int a[],int left,int right){
    if(left>=right){
        return;
    }
    int m = left + (right-left)/2;
    mergeSortit(a,left,m);
    mergeSortit(a,m+1,right);
    merge(a,left,m,right);
}

int main(){
    ofstream input;
    input.open("3.txt",ios::in);
    int testcases;
    testcases = rand()%10+1;
    input << testcases << endl;
    while(testcases--){
        int num1;
        num1 =1000;
        input << num1  << endl;
        for(int i=0;i<num1;i++){
            input << rand()%200 << " ";
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("3.txt","r",stdin);
	    freopen("3out.txt","w",stdout);
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
        mergeSortit(a,0,n-1);
        for(int i=0;i<n;i++){
            cout << a[i] << " " ;
        }
        cout << endl;
        

    }
}