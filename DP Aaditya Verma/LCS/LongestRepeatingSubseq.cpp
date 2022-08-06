#include <bits/stdc++.h>
#include<iostream>
using namespace std;

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
            if(x[i-1] == y[j-1] && i != j){
                tab[i][j] = 1 + tab[i-1][j-1]; 
            }
            else{
                tab[i][j] =  max( tab[i][j-1], tab[i-1][j] );
            }
        }
    }
    return tab[n][m];
}

int main(){
    string x = "AABEBCDD";
    string y = x; // make same as first string
    int n = x.length();
    int m = y.length();
    
    cout << "LRepeatingSubSeq = " << LCSTab(x,y,n,m) << endl;

}
