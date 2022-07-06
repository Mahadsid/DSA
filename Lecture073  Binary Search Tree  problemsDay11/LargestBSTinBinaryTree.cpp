#include <bits/stdc++.h>
#include<iostream>
#include<queue>
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

class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(node* root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right =  solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size +1 ;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    //check for BST
    if(left.isBST && right.isBST && (root->data >left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //ans update
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(node* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
//tc=0(n)