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

int solve(node * root, int &i, int k){
    //base case
    if(root == NULL){
        return -1;
    }
    //making inorder bcs it is sorted  in BST
    //L
    int left = solve(root->left,i , k);
    if(left != -1){
        return left;
    }

    //N
    i++;
    if(i==k){
        return root->data;
    }

    //R
    return solve(root->right, i, k);
}//tc=0(n), sc=0(H)

int kthSmallest(node * root, int i, int k){
    int ans = solve(root , i, k);
    return ans;
}
//using morris travel solve it and make time complexity 0(1)

//Kth Largest == (n-k)+1 