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


bool isCircular(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return true;
    }
    Node* temp = head -> next;

    if(head != temp && temp != NULL){
        temp = temp -> next;
    }
    if (temp == head)
    {
        return true;
    }
    return false;
 
}