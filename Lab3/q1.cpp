#include <iostream>
using namespace std;

// for naive method time complexity is O(n^(3))

vector<vector<int> > naive(vector<vector<int> > mat1,vector<vector<int> > mat2,int m,int n,int p,int q){
    
    vector<vector<int> > ans(m,vector<int>(q,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            for(int k=0;k<n;k++){
                ans[i][j] += mat1[i][k] * mat2[k][j]; 
            }
        }
    }
    return ans;
}

// This is divide and conquer method

// In this code I can multiply any order matrix if it satisfies m*n n*p 

// transform funtion is used to transform matrix order to nearest 2 power matrix

void transform(vector<vector<int> > &mat,int max,int m,int n ){
    
    int pow = 0;
    while(max>(1<<pow)){
        pow++;
    }
    max = 1<<pow;
    for(int i=0;i<max;i++){
        if(i<m){
            for(int j=n;j<max;j++){
                mat[i].push_back(0);
            }
        }else{
            vector<int> v(max);
            mat.push_back(v);
        }
    }
   
}

// print function is used to print the matrx of specific area Time Complexity is O(n^2)

void print(vector<vector<int> > mat,int startrow,int startcol,int length,int width){
    for(int i=startrow;i<(startrow+length);i++){
        for(int j=startcol;j<(startcol+width);j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void print(vector<vector<int> > mat){
    int m = mat.size();
    int n = mat[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// matAddition function is used to add two matrices Time Complexity: O(n^2)

void matAddition(vector<vector<int> > mat1,vector<vector<int> > mat2,vector<vector<int> >& ans,int startrow,int startcol,int length,int width){
    for(int i=startrow;i<(startrow+length);i++){
        for(int j=startcol;j<(startcol+width);j++){
            ans[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void matSubtraction(vector<vector<int> > mat1,vector<vector<int> > mat2,vector<vector<int> >& ans,int startrow,int startcol,int length,int width){
    for(int i=startrow;i<(startrow+length);i++){
        for(int j=startcol;j<(startcol+width);j++){
            ans[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

//matMultiplication is used for multiplication Time Complexity is O(n^3)

// T(n) = 8*T(n/2) + n*c;

//from masters theorem we get time complxity as O(n^(3)) which is similar to brute force algorithm

vector<vector<int> > matMultiplication(vector<vector<int> > mat1,vector<vector<int> > mat2,int startrow,int startcol,int startrow1,int startcol1,int startrow2,int startcol2,int length,vector<vector<int> >& result){
    if(length==1){
        result[startrow][startcol] = mat1[startrow1][startcol1]*mat2[startrow2][startcol2];
        return result;
    }
    if(length==2){

        result[startrow][startcol] = mat1[startrow1][startcol1]*mat2[startrow2][startcol2] + mat1[startrow1][startcol1+1]*mat2[startrow2+1][startcol2];
        result[startrow][startcol+1] = mat1[startrow1][startcol1]*mat2[startrow2][startcol2+1] + mat1[startrow1][startcol1+1]*mat2[startrow2+1][startcol2+1];
        result[startrow+1][startcol] = mat1[startrow1+1][startcol1]*mat2[startrow2][startcol2] + mat1[startrow1+1][startcol1+1]*mat2[startrow2+1][startcol2];
        result[startrow+1][startcol+1] = mat1[startrow1+1][startcol1]*mat2[startrow2][startcol2+1] + mat1[startrow1+1][startcol1+1]*mat2[startrow2+1][startcol2+1];
        return result;
        
    }
    matAddition(matMultiplication(mat1,mat2,startrow,startcol,startrow1,startcol1,startrow2,startcol2,length/2,result),matMultiplication(mat1,mat2,startrow,startcol,startrow1,startcol1+length/2,startrow2+length/2,startcol2,length/2,result),result,startrow,startcol,length/2,length/2);
    matAddition(matMultiplication(mat1,mat2,startrow,startcol+length/2,startrow1,startcol1,startrow2,startcol2+length/2,length/2,result),matMultiplication(mat1,mat2,startrow,startcol+length/2,startrow1,startcol1+length/2,startrow2+length/2,startcol2+length/2,length/2,result),result,startrow,startcol+length/2,length/2,length/2);
    matAddition(matMultiplication(mat1,mat2,startrow+length/2,startcol,startrow1+length/2,startcol1,startrow2,startcol2,length/2,result),matMultiplication(mat1,mat2,startrow+length/2,startcol,startrow1+length/2,startcol1+length/2,startrow2+length/2,startcol2,length/2,result),result,startrow+length/2,startcol,length/2,length/2);
    matAddition(matMultiplication(mat1,mat2,startrow+length/2,startcol+length/2,startrow1+length/2,startcol1,startrow2,startcol2+length/2,length/2,result),matMultiplication(mat1,mat2,startrow+length/2,startcol+length/2,startrow1+length/2,startcol1+length/2,startrow2+length/2,startcol2+length/2,length/2,result),result,startrow+length/2,startcol+length/2,length/2,length/2);

    return result;
}





int main(){
     #ifndef ONLINE_JUDGE
	    freopen("1.txt","r",stdin);
	    freopen("1output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int m,n,p,q;
        cin >> m >> n >> p >> q;
        // m = 2,n=3,p=3,q=5;
        if(n==p){
            vector<vector<int> > mat1(m,vector<int>(n,0)),mat2(p,vector<int>(q,0)),ans(m,vector<int>(q,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cin >> mat1[i][j];
                }
            }
            for(int i=0;i<p;i++){
                for(int j=0;j<q;j++){
                    cin >> mat2[i][j];
                }
            }
            int c = max(max(m,n),max(p,q));
            transform(ans,c,m,q);
            transform(mat1,c,m,n);
            transform(mat2,c,p,q);

            // cout << endl;
            // print(mat1);
            // cout << endl;
            // print(mat2,0,0,p,q);
            // cout << endl;
            // print(ans);
            // cout << endl;
            ans = matMultiplication(mat1,mat2,0,0,0,0,0,0,ans.size(),ans);
            print(ans,0,0,m,q);
            cout << endl;
            // ans = naive(mat1,mat2,m,n,p,q);
            // print(ans,0,0,m,q);
         }else{
            cout << "Invalid input " << endl;
        }

    }

}