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


int countNode(node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    int ans = 1 + countNode(root->left) + countNode(root->right);
}

bool isCBT(node* root, int index, int cnt){
    //base case
    if(root == NULL){
        return true;
    }
    if(index >= cnt){ //for zero base indexing we using =
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*index+1, cnt); // for zerp base indexing
        bool left = isCBT(root->right, 2*index+2, cnt);
        return (left && right);
    }
}

bool isMaxOrder(node* root){
    //leaf node
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    //only left exists
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if(left && right && (root->data > root->right->data && root->data > root->left->data)){
            return true;
        }
        else{
            return false;
        }

    }
    
}



bool isHeap(node* root){

    int index=0;
    int totalCount= countNode(root);
    if(isCBT(root, index, totalCount) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}
//tc=0(n) +0(n)+0(n)= 0(n), sc=0(H)
