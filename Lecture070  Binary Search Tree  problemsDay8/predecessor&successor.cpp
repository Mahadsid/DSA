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



pair<int, int> predessorSuccessor(node * root, int key){

    //find key
    node * temp = root;
    int pre = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if(temp->data > key){
            /* data bda h to key left m hogi or data bda h to wo possible succesor h 
             to use store kra liya  but pehle save krna fir age traverse krna h*/
             succ = temp->data;
             temp = temp->left;
              
        }
        else {
            // same right k liy
            pre = temp->data;
            temp= temp->right;
            
        }
    }

    //pred and succ

    //pred
    node * leftTree = temp->left;
    while (leftTree != NULL)
    {
        //right bhagne s phle ans save kra liya
        pre = leftTree->data;
        // max nikalna h to right bhagte raho
        leftTree= leftTree->right;
    }

    //succc
    node * rightTree = temp->right;
    while (rightTree != NULL)
    {
        //right bhagne s phle ans save kra liya
        succ = rightTree->data;
        // min nikalna h to left bhagte raho
        rightTree= rightTree->left;
    }
    
    pair<int, int> ans = make_pair(pre,succ);
    return ans;
    
}//tc=0(n), sc=0(1)