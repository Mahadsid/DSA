
#include<iostream>
using namespace std;
class Node {

    public:
    int data;
    Node* next;

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
// approach 1 itterative TC= 0(n), SC= 0(1)
Node * reverseLL(Node * &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
       forward = curr -> next;
       curr-> next = prev;
       prev = curr;
       curr = forward;
    }
    return prev;
}

// approach 2 Recurrsive TC= 0(n), SC= 0(1)
Node * reverse(Node * &head, Node * curr, Node* prev){
    //Base Case
    if(curr != NULL){
        head = prev;
        return;
    }
    Node* forward = curr -> next;
    reverse(head, forward,curr);
    curr-> next = prev;

}
Node* reverseLLl(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

// another sol with recurresion
Node * reverseL(Node * &head){

    //base case
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* chotahead = reverseL(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return chotahead;

}
Node * reverseL1(Node* head){
    return reverseL(head);
}



int main() {
    
    
    
    

    return 0;
}