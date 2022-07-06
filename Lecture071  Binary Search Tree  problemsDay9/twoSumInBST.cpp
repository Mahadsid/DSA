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


void inorder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twosumBST(node * root ,int target){
    vector<int> inorderval;
    //store inorder
    inorder(root, inorderval);

    //two pointer approach
    int i=0, j=inorderval.size() - 1;

    while (i<j){
        int sum = inorderval[i] + inorderval[j];
        if (sum == target)
        {
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        } 
    }
    return false;
   
}//tc=0(n),sc=0(n)