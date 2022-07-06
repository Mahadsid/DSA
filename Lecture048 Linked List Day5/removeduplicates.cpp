#include<iostream>
#include<map>
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

//from sorted link list

Node* uniquesorted(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    Node* curr = head;
    
    

    while (curr != NULL)
    {
        if ((curr ->next != NULL) && curr ->data == curr -> next -> data)
        {
            Node* nextkanext = curr ->next ->next;
            Node* nodetodelete = curr ->next;
            delete(nodetodelete);
            curr ->next = nextkanext;
        }
        else{
            curr = curr ->next;
        }
        
    }

    return head;
}
//TC=0(n) sc=0(1)

Node* uniqueunsorted(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    Node* curr = head;
    
    

    while (curr != NULL)
    {
        Node* temp = curr->next;
        while(temp != NULL){
            if ((curr ->next != NULL) && curr ->data == temp-> data)
            {
            Node* nextkanext = curr ->next ->next;
            Node* nodetodelete = curr ->next;
            delete(nodetodelete);
            curr ->next = nextkanext;
            }
            else{
            temp = temp ->next;
        }
        }
        
        curr = curr->next;     
    }

    return head;
}
//TC=0(n^2) sc=0(1)

