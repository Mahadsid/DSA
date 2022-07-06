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

Node * Kreverse(Node * head, int k){
    if(head == NULL ){
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count=0;

    while(curr != NULL && count < k){
       next = curr -> next;
       curr-> next = prev;
       prev = curr;
       curr = next;
       count++;
    }
    //step 2 recusrrsion dekh lega
    if (next != NULL)
    {
        head -> next = Kreverse(next, k);
    }
    // step3  
    return prev;

}
//TC = 0(N) SC = 0(N)