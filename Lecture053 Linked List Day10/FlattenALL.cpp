#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Node {

    public:
    int data;
    Node* next;
    Node* random;
    Node* right;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

Node* merge(Node* left, Node* right){

    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL)
    {
        if(left->data < right ->data){
            temp -> next = left;
            temp = left;
            left= left->next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while (left != NULL)
    {
        temp -> next = left;
        temp = left;
        left= left->next;
    }

    while (right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans->next;
    return ans;
}

Node* flattenLL(Node* head){
    Node* down = head;
    down->next = NULL;
    Node* rightLL = flattenLL(head->right);

    Node* ans = merge(down , rightLL);

    return ans;
}
//h/w