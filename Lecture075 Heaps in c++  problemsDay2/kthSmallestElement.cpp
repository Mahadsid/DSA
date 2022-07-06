#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int kthsmallestelement(int arr[], int l, int r, int k){
    priority_queue<int> pq;
    //step1
    for(int i = 0; i<k; i++){
    pq.push(arr[i]);
    }
    //step2
    for(int i =k; i<=r; i++){
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //step3
    return pq.top();
}
//sc=0(k)