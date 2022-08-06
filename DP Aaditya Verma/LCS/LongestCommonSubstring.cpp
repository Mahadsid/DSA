#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//LCSb = continous

//Tab
int LCSubStr(string x, string y, int n, int m){
    vector<vector<int>> tab(n+1, vector<int>(m+1));
    for(int i = 0; i<n+1; i++){
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0){
                tab[i][j] = 0;
            }
        } 
    }
    int max = 0;
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++)
        {   
            if(x[i-1] == y[j-1]){
                tab[i][j] = 1 + tab[i-1][j-1]; // 1+ match hua
            }
            else{//continuity break hogyi
                tab[i][j] = 0;
            }
            if(tab[i][j] > max){
                max = tab[i][j];
            }
        }
    }
    return max;
}

int main(){
    string x = "abcde";
    string y = "abfce";
    int n = x.length();
    int m = y.length();
    //op {ab}{c}{e} -> longest = {ab} ->= 2;
    
    //tabulation
    cout << "LCSubStr = " << LCSubStr(x,y,n,m) << endl;

}