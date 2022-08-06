#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Matrix Chain Multiplication

//Recursive
int MCMRec(vector<int> arr, int i, int j){
    //Base Cond
    if(i >= j){
        return 0;
    }
    int mini = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempans = MCMRec(arr, i , k) + MCMRec(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
       
        mini = min(tempans, mini);
        
    }
    return mini;
}

//TopDown Memo
int MCMMemo(vector<int> arr, int i, int j){
    vector<vector<int>> t(arr.size()+1, vector<int>(arr.size()+1, -1));
    //Base Cond
    if(i >= j){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int mini = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempans = MCMMemo(arr, i , k) + MCMMemo(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
       
        mini = min(tempans, mini);
        
    }
    return t[i][j] = mini;
}


int main(){
    vector<int> arr = {10,30,5,60};
    int i = 1;
    int j = arr.size() - 1;

    //Recursive
    cout << "Min Cost Of Mul (REC) = " << MCMRec(arr, i , j) << endl;
    cout << "Min Cost Of Mul (MEM) = " << MCMMemo(arr, i , j) << endl;

}