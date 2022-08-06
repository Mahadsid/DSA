#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// MiN # Of coins to make up the sum
//Twist in Inialization


int CoinChange2(vector<int> arr,int n, int sum){
    // Base condition ko hi initialization m change hojati h n=0 so zero row m full(0); zero col/cap = full(0)
    vector<vector<int>> tab(n+1, vector<int>(sum+1));
    for (int i = 0; i < n+1; i++)
    {
        tab[i][0] = 0;
    }
    for (int i = 0; i < sum+1; i++)
    {
        tab[0][i] = INT_MAX-1;
    }
    //Intitialize second row
    for (int j = 1; j < sum+1; j++)
    {
        tab[0][j] = j % arr[0] ? INT_MAX - 1 : j/arr[0];
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++)
        {   
            if(arr[i-1] <= j){
                tab[i][j] = min( (1 + tab[i][j-arr[i-1]]) , ( tab[i-1][j]) );
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
    vector<int> arr = {1,2,3};
    int sum = 5;
    //tabulation
    cout << CoinChange2(arr, arr.size(), sum) << " = " << "Tablulation" << endl;
    //op = 2 correct
    return 0;
}