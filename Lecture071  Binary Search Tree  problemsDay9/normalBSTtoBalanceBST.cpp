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

node * inorderToBST(int s, int e , vector<int> &inorderval){
    //base case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(inorderval[mid]);
    root->left = inorderToBST(s, mid-1, inorderval);
    root->right = inorderToBST(mid+1, e, inorderval);
    return root;
}

node * BalancedBST(node * root){
    vector<int> inorderval;
    //store inorder
    inorder(root, inorderval);

    return inorderToBST(0, inorderval.size()-1, inorderval);


}//tc=0(n),sc=(n)