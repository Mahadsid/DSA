#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Matrix Chain Multiplication

//Recursive
int MCMRec(vector<int> arr, int i, int n){
    //Base Cond
    if(i >= n){
        return 0;
    }
    int temp = arr[i] * arr[i-1];
    for(int k = i+2; k<n; k++){
        int tempans = MCMRec(arr, k, n);

        temp = max(temp, tempans);
    }
    return temp;
    
}

long long minCost(long long arr[], long long n){

    //priority_queue<long long, vector<long long>, greater<long long> > pq; //minheap
    stack<long long> s;
    for(int i = 0; i < n; i++){
        s.push(arr[i]);
    }
    vector<long long> v;

    while (s.size() > 0)
    {
        long long a = s.top();
        s.pop();
        long long b = s.top();
        s.pop();

        long long t1 = a*b;
        v.push_back(t1);
        long long a1 = s.top();
        s.pop();
        long long b1 = s.top();
        s.pop();

        long long t2 = a1*b1;
        v.push_back(t2);

    }

    long long mx;
    for(int i = 0; i < v.size()-1 ;i++){
        mx = max(mx , v[i]); 
    }
    return mx;
}


// //TopDown Memo
// int MCMMemo(vector<int> arr, int i, int n){
//     vector<vector<int>> t(arr.size()+1, vector<int>(arr.size()+1, -1));
//     //Base Cond
//     if(i >= n){
//         return 0;
//     }
//     if(t[i][n] != -1){
//         return t[i][n];
//     }
//     int temp = arr[i] * arr[i-1];
//     for(int k = i+2; k<n; k++){
//         int tempans = MCMMemo(arr, k, n);

//         t[i][n] = max(temp, tempans);
//     }
//     return t[i][n];
// }


int main(){
    vector<int> arr = {-11 ,8, 10, 9, -19, -8, 19, -14};
    int i = 1;
    int j = arr.size()-1;

    long long arr1[] = {-12, 17, -13, 17};
    long long n = 4;


    //Recursive
    //cout << "Min Cost Of Mul (REC) = " << MCMRec(arr, i , 8) << endl;
    cout << "Min Cost Of Mul (MEM) = " << minCost(arr1, n) << endl;

}