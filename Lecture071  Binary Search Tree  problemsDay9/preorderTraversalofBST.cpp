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

// bst from preorder

//tc=0(n)

node* solve(vector<int> & preorder, int mini, int maxi, int &i){
    if(i >= preorder.size())
        return NULL;
    
    if(preorder[i] < mini || preorder[i] > maxi) //range s bahar h
        return NULL;
    
    node * root = new node(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

node* preorderToBSt( vector<int> & preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i =0;
    return solve(preorder, mini, maxi,i);

}