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

//tc=0(m+n) , sc=0(m+n)

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

vector<int> mergedArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i=0, j=0;
    int k = 0;
    while (i<a.size() && j <b.size())
    {
        if(a[i] < b[i]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[i];
            j++;
        }
    }
    
    while (i<a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    { 
        ans[k++] = a[j];
        j++;
    }
    return ans;
}

void inorder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node * Merge2BST(node * root1, node * root2){
    //step1 store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    //step 2 merge arrays 
    vector<int> mergedarray =  mergedArrays(bst1, bst2);
    int s = 0, e= mergedarray.size()-1;
    return inorderToBST(s, e, mergedarray);
} 

//optimize sc=0(h1 + h2)..
//step 1 convert to two sorted Link List(By using logic of flatten BST)
//Merge two sorted Link List
//sorted LL to BST(valid BST basically)

//convert a BST into SLL (tree to doubly LL)
/* 
convert convert right subtree to LL (gives head of ll)
root.right = head
head.left = root
head = root
convert convert left subtree to LL (gives head of ll)
*/

void convertIntoSortedDLL(node* root, node* &head){
    //base case
    if(root == NULL){
        return;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

// merge two sorted into one

node * mergeLL(node * head1, node* head2){
    node* head=NULL;
    node* tail=NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right; 
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right; 
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
                
            }

        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;           
    }
    return head;
    
}
////sorted LL to BST
/* 
n/2 tk left subtree bna lo LL s
n/2 k agalga jo node h usse root node bna do
root.left m left subtree lga do
head ko next kro ya root k next wla node
wha s right subtree bna lo bcha hua n-n/2-1 LL s
ROOT.RIGHT m y right subtree lga do
*/

int countNodes(node* head){
    int cnt = 0;
    node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

node* sortedLLtoBST(node* &head, int n){
    //basecase
    if (n <= 0 || head == NULL)
    {
        return NULL; 
    }
    node* leftsubtree = sortedLLtoBST(head, n/2);
    node* root = head;

    root->left = leftsubtree;
    head = head->right;

    root->right = sortedLLtoBST(head, n-n/2-1);
    return root;
}

node* Merge2BSTnew(node* root1 , node* root2)
{
    //step 1 convert bst into sorted LL
    node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //step 2 merge 2 sorted LL
    node* head = mergeLL(head1, head2);

    //step 3 covert sorted LL into BST
    return sortedLLtoBST(head, countNodes(head));
}

//sc=0(H)