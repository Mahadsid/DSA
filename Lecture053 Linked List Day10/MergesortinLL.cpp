#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Node {

    public:
    int data;
    Node* next;
    Node* random;

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

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast ->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

//logic of merge two sorted LL
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

// change links only
Node* mergesortLL(Node* head){
    //base case
    if((head == NULL) || (head -> next =NULL)){
        return head;
    }
    
    //break LL into two halves , after finding mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;

    mid->next = NULL;

    //recusive call to sort both halves
    left = mergesortLL(left);
    right = mergesortLL(right); 

    //merege both left and right halves

    Node* result = merge(left, right);

    return result;
}//TC=0(nLogn) SC=0(Log n)

// IMP ques:-> why we prefer merge sort in LL and quick sort in arrays?