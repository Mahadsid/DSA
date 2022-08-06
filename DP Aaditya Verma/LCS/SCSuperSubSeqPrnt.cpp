#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//print shortest Common Super Subsequence

string LCSTab(string x, string y, int n, int m){
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
    string s = "";
    int i=n, j=m;
    while (i>0 && j>0)
    {
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(tab[i][j-1] > tab[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }
            else if(tab[i][j-1] < tab[i-1][j]){
                s.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(x[j-1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";

    int n = x.length();
    int m = y.length();
    
    //op = acbcdaf  
    
    cout << "Print SCSuperSeq = " << LCSTab(x,y,n,m) << endl;
}