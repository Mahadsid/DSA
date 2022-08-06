#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//prblm = related to Knapsack->SubSumPrblm

//Bottom up Tabulation
bool SubSumTab(vector<int> arr,int n, int sum){
    if(n==0 || sum == 0){
        return true;
    }
    // Base condition ko hi initialization m change hojati h n=0 so zero row m full(0); zero col/cap = full(0)
    vector<vector<bool>> tab(n+1, vector<bool>(sum+1));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0){
                tab[i][j] = false;
            }
            if(j==0){
                tab[i][j] = true;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++)
        {   
            if(arr[i-1] <= j){
                tab[i][j] = (tab[i][j-arr[i-1]]) || ( tab[i-1][j] );
                //
            }
            else if(arr[i-1] > j){
                tab[i][j] = tab[i-1][j]; 
            }      
        }
    }
    return tab[n][sum];
}

bool EqualSumPar(vector<int> arr,int n){
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    else if(sum % 2 == 0){
        return SubSumTab(arr, arr.size(), sum/2);
    } 
}
int main(){
    vector<int> arr = {1,5,11,5};

    //tabulation
    cout << EqualSumPar(arr, arr.size()) << " = " << "Tablulation" << endl;
    
    return 0;
}