#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//prblm = related to Knapsack->SubSumPrblm
//Bottom up Tabulation
int CountSubSum(vector<int> arr,int n, int sum){
    if(n==0 || sum == 0){
        return 0;
    }
    // Base condition ko hi initialization m change hojati h n=0 so zero row m full(0); zero col/cap = full(0)
    vector<vector<int>> tab(n+1, vector<int>(sum+1));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0){
                tab[i][j] = 0;
            }
            if(j==0){
                tab[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++)
        {   
            if(arr[i-1] <= j){
                tab[i][j] = (tab[i-1][j-arr[i-1]]) + ( tab[i-1][j] );
                //(no leliya to use minus krdo )||(no ni liya) jisse bhi subset true ayega use store krlenge
            }
            else if(arr[i-1] > j){
                tab[i][j] = tab[i-1][j]; 
            }      
        }
    }
    return tab[n][sum];
}

int main(){
    vector<int> arr = {2,3,5,6,8,10};
    int sum = 10;
    // vector<int> arr = {1,2,3};
    // int sum = 4;
    //tabulation
    cout << CountSubSum(arr, arr.size(), sum) << " = " << "Tablulation" << endl;
    
    return 0;
}