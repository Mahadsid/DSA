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

bool isBST(node * root, int min, int max){
    // base case
    if(root == NULL){
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right,  root->data, max);
        return left && right;
    }
    else{
        return false;
    }
    
} //tc=0(n), sc=0(H)

bool validateBST(node * root){
    return isBST(root, INT_MIN, INT_MAX);
}