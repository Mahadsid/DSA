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

// base case if null reach so data is absent,, if root.data > X left part else right part

bool searchInBST( node * root , int x){
    // base case
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (root->data > x)
    {
        //left m 
        return searchInBST(root->left ,x);
    }
    else{
        //right m
        return searchInBST(root->right ,x);
    }

}

//tc= 0(log n) or skewed =0(H) or 0(n) ,, sc=0(N)

bool searchInBSTiterative( node * root , int x){
    
    node *  temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
    {
        return true;
    }
    if (temp->data > x)
    {
        //left m 
        temp = temp->left;
    }
    else{
        //right m
        temp = temp->right;
    }
    }
    return false; //data ni mila

}
// sc =0(1)

// deletion in BST
