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

//lowest common ancestor in BST

node * LCAinBST(node * root, node * P, node * Q){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data){
        return LCAinBST(root->right,P ,Q);
    }
    if(root->data > P->data && root->data > Q->data){
        return LCAinBST(root->left,P ,Q);
    }

    return root;
}//tc=0(n) sc=0(H)

node * LCAinBSTiterative(node * root, node * P, node * Q){
    //base case
    if(root == NULL){
        return NULL;
    }

    while (root != NULL)
    {
        if(root->data < P->data && root->data < Q->data){
        return LCAinBST(root->right,P ,Q);
    }
        else if(root->data > P->data && root->data > Q->data){
        return LCAinBST(root->left,P ,Q);
    }
        else{
            return root;
        }
    
    

    
}//tc=0(n) sc=0(1)

