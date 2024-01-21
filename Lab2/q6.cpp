#include <iostream>
#include <fstream>
using namespace std;

// in theis question time complexity is O(nlogn) average case

int partition(int a[],int l,int r){
    int n = r-l+1;
    int pivot = l+n/2;
    int i=l,j=l;
    while(j<=r){
        if(a[j]<a[pivot]){
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    swap(a[i],a[pivot]);
    return i;
}

void QuickSort(int a[],int l,int r){
    if(l>=r) return;

    int piv = partition(a,l,r);
    QuickSort(a,l,piv-1);
    QuickSort(a,piv+1,r);
}

int main(){
    ofstream input;
    input.open("6.txt",ios::in);
    int testcase;
    testcase = rand()%100;
    input << testcase << endl;
    while(testcase--){
        int num = rand()%1000;
        input << num << endl;
        for(int i=0;i<num;i++){
            input << rand() << " ";
        }
        input << endl;
    }
    #ifndef ONLINE_JUDGE
	    freopen("6.txt","r",stdin);
	    freopen("6out.txt","w",stdout);
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
        QuickSort(a,0,n-1);
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}