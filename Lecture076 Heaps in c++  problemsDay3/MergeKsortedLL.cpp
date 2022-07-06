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

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

Node* MergeKsortedLL(vector<Node*> &listArray){

    priority_queue<Node*, vector<Node*>, compare > minHeap;

    int k = listArray.size();

    if(k == 0){
        return NULL;
    }
    //step1
    for (int i = 0; i < k; i++)
    {
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;
    while (minHeap.size() > 0)
    {
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){ // LL is empty
            head = top;
            tail = top;
        } 
        else{ // insert at end
            tail->next = top;
            tail = top;
        }

    }
    return head;

}
//tc=0(k logk) sc=0(k)