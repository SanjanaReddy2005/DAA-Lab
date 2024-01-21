#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;

// this is the partion function to keep track of index of pivot which helps use to decide the which part of the array shoould be further pass in quick sort so that we can get the median.
int partition(int a[],int l,int r){
    int last = a[r];
    int i=l,j=l;
    while(j<=r){
        if(last>a[j]){
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    swap(a[i],a[r]);
    return i;
}



void medianTrack(int a[],int l,int r,int mid,int& mid1,int& mid2){// mid1 and mid2 are to keep track of both mid and mid-1 elements in case of n is even we can acces the mid-1 indexed element in array
    if(l>=r) return;
    int pIndex = partition(a,l,r);
    // cout << pIndex << endl;
    if(pIndex == mid){
        mid2 = pIndex;
        if(mid1!=-1){
            return;
        }
    }
    if(pIndex == mid-1){
        mid1 = pIndex;
        if(mid2!=-1) return;
    }
    // Here either we have to go left side of the array if pivot index is larger than the mid index(n/2) or right of the array if the pivot index is less than n/2
    if(pIndex>=mid){
        medianTrack(a,l,pIndex-1,mid,mid1,mid2); 
        return;
    }else{
        medianTrack(a,pIndex+1,r,mid,mid1,mid2);
        return;
    }
}

float median(int a[],int n){
    
    int mid1 = -1,mid2=-1;
    if(n%2==1){
        medianTrack(a,0,n-1,n/2,mid1,mid2);
        return a[mid2];
    }
        medianTrack(a,0,n-1,n/2,mid1,mid2);
        return (a[mid1]+a[mid2])/2.0;
}

int main(){
    ofstream input;
    input.open("4.txt",ios::in);
    int testcases;
    testcases = 100000;
    input << testcases << endl;
    while(testcases--){
        int num1;
        num1 =10;
        input << num1  << endl;
        for(int i=0;i<num1;i++){
            input << rand()%200 << " ";
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("4.txt","r",stdin);
	    freopen("4out.txt","w",stdout);
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
    float Median = median(a,n);
    cout << Median << endl;
    
    }
}