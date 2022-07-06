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

void inorder(node* &root) { // always in sorted order
    //base case
    
    if(root == NULL) {
        return ;
    }

    
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

node * insertIntoBST(node * &root, int d){
    //base case
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        //right m insert krna h
        root->right = insertIntoBST(root->right, d);
    }
    else{
        // left m insert krna h
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}//tc=o(logn)

void levelOrderTraversal(node* root) { // BFS 
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

node * minValue(node * &root){
    node * temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node * maxValue(node * &root){
    node * temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

node * deleteFromBST(node * root, int val){
    //base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if (root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if (root->left == NULL && root->right != NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return  root;
        }
    }
    
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
    }
    


void takeinput(node * &root){

    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }

}

int main(){
    node * root = NULL;
    cout << "entr data to insert in BST" << endl;
    takeinput(root);


    cout << "LVL ORDER T " << endl;
    levelOrderTraversal(root);
    
    cout << "INORDER" << endl;
    inorder(root);
    
    return 0;
}