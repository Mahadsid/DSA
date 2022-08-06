#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//full same as unbknapsack
int rodCutting(vector<int> length, int size, vector<int> Price, int N){
    vector<vector<int>> tab(size+1, vector<int>(N+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < N+1; j++)
        {
            if(i==0 || j==0){
                tab[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < size+1; i++){
        for (int j = 1; j < N+1; j++)
        {   
            if(length[i-1] <= j){
                tab[i][j] = max( Price[i-1] + tab[ i ][j-length[i-1]], tab[i-1][j] );
            }
            else if(length[i-1] > j){
                tab[i][j] = tab[i-1][j]; 
            }      
        }
    }
    return tab[size][N];
}

int main(){
    vector<int> length = {1,2,3,4,5,6,7,8};
    //if length arr not given fill it with 1 to size of price arr
    vector<int> Price = {1,5,8,9,10,17,17,20};
    int size = 8;
    int totLnth = 8;
    int profit = rodCutting(length, size, Price, totLnth);
    cout << "Profit = " << profit << endl;
}