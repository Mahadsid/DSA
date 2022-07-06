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

//flatten bst -> linklist and make it sorted

void inorder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node* flatten(node* root){
    vector<int> inorderval;
    //store inorder
    inorder(root, inorderval);

    int n = inorderval.size();

    node* newRoot = new node(inorderval[0]);
    node* curr = newRoot;

    for (int i = 1; i < n; i++)
    {
        node * temp = new node(inorderval[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    //final step

    curr->left=NULL;
    curr->right=NULL;

    return newRoot;
}//tc=0(n),sc=(n)