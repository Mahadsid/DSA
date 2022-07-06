#include <bits/stdc++.h>
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

bool detectloop(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return false;
    }
    map<Node*, bool> visited;

    Node* temp = head;

    while (temp!= NULL )
    {
        //cycle is present
        if (visited[temp]==true)
        {
            cout << "Present on element " << temp->data << endl;
            return 1; 
        }
        visited[temp] = true;
        temp= temp->next;
    }
    return false;
}
//tc = 0(N) sc=0(N)

//to reduce space we use floyd cycle detection algorithm

// slow == fast khiladi = loop is present

Node* FloydCycleDetect(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast= fast -> next;
        if(fast != NULL){
            fast= fast -> next;
        }
        slow= slow -> next;
    }
    //looop present
    if(slow==fast){
        cout << "Present on element " << slow->data << endl;
        return slow;
    }
    
    return NULL;
}
//TC=0(N) SC=0(1)


//node where loop starts?
Node* getstartingnode(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    Node* intersection = FloydCycleDetect(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    
    Node* slow = head;
    

    while (slow != intersection)
    {
        slow= slow -> next;
        intersection = intersection -> next;
    }


    return slow;
}

//remove loop
Node* removeloop(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    Node* startofloop = getstartingnode(head);
    if (startofloop == NULL)
    {
        return head;
    }
    
    Node* temp = startofloop;
    

    while (temp ->next != startofloop)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;

    return;
}
//TC= 0(N),sc=0(1)

/*
tc=0(n) sc=0(1) but less complexity
ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }*/