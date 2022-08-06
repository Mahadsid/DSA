#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//LCS ->discontinous

//recursive 
int LCSrec(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1 + LCSrec(x, y, n-1, m-1); // 1+ match hua
    }
    else{//match ni krra
        return max( LCSrec(x,y,n,m-1), LCSrec(x,y,n-1,m) );
    }
}

//memo
int LCSMemo(string x, string y, int n, int m){
    vector<vector<int>> t(n+1, vector<int>(m+1, -1));
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(x[n-1] == y[m-1]){
        t[n][m] = 1 + LCSMemo(x, y, n-1, m-1); // 1+ match hua
    }
    else{//match ni krra
        t[n][m] =  max( LCSMemo(x,y,n,m-1), LCSMemo(x,y,n-1,m) );
    }
    return t[n][m];
}

//Tab
int LCSTab(string x, string y, int n, int m){
    vector<vector<int>> tab(n+1, vector<int>(m+1, -1));
    for(int i = 0; i<n+1; i++){
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0){
                tab[i][j] = 0;
            }
        } 
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++)
        {   
            if(x[i-1] == y[j-1]){
                tab[i][j] = 1 + tab[i-1][j-1]; // 1+ match hua
            }
            else{//match ni krra
                tab[i][j] =  max( tab[i][j-1], tab[i-1][j] );
            }
        }
    }
    return tab[n][m];
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.length();
    int m = y.length();
    //op - 4 ; a b d h  
    //recursion
    cout << "LCS-Rec = " << LCSrec(x,y,n,m) << endl;
    //memoization
    cout << "LCS-Memo = " << LCSMemo(x,y,n,m) << endl;
    //tabulation
    cout << "LCS-Tab = " << LCSTab(x,y,n,m) << endl;

}