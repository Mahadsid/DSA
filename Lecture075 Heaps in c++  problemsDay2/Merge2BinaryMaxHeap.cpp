#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//FOR 0 BASE INDEXING 
void heapify(vector<int> &arr, int n, int i){ //tc=0(logn)
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && arr[largest] < arr[left]){
        largest = left;    
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;    
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){
    //step 1 merge two arrays

    vector<int> ans;
    for(auto i:a){
        ans.push_back(i);
    }
    for(auto i:b){
        ans.push_back(i);
    }


    //step 2 build heap using array for 0 base indexing 
    int size = ans.size();
    for(int i = size/2 - 1; i>=0; i--){ //n/2-1 to >=0 these are non leaf node
        heapify(ans, n, i);
    }

    return ans;
}