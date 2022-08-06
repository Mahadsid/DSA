#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int LCSTab(string x, string y, int n, int m){
    vector<vector<int>> tab(n+1, vector<int>(m+1));
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
    string x = "AXYZ";
    string y = "ABXCPY";
    int n = x.length();
    int m = y.length();
    //op - 4 ; a b d h  

    //tabulation
    int ans = LCSTab(x,y,n,m);
    if(ans == n){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}