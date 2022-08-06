#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Min NO of Insertion & Deletion To Make str A -> str B

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
    string x = "heap";
    string y = "pea";
    int n = x.length();
    int m = y.length();
    
    //op = no of del = 2
    //     no   of ins = 1
    // formula #of del = x.len - LCS
    // formula #of ins = y.len - LCS
    
    int del = n - LCSTab(x,y,n,m);
    int ins = m - LCSTab(x,y,n,m);

    cout << "# of Del = " << del << endl;
    cout << "# Of Ins = " << ins <<endl;
}