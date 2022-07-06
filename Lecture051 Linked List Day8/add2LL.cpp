#include<iostream>
#include<map>
#include<vector>
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
// two LL is given add them and give ans

void insertAtTail(Node* &head,Node* &tail, int value){
    Node* temp = new Node(value);
    //if list is empty
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* addeasycode(Node * first, Node* second){
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum %10;
        
        //node add at ans LL
        insertAtTail(ansHead,ansTail,digit);
        carry = sum/10;

        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return ansHead;

}



Node* add(Node * first, Node* second){
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;


    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum %10;
        
        //node add at ans LL
        insertAtTail(ansHead,ansTail,digit);

        carry = sum/10;

        first = first->next;
        second = second->next;

        while (first != NULL)
        {
            int sum = carry + first->data;
            int digit = sum %10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            first = first->next;
        }

        while (second != NULL)
        {
            int sum = carry + second->data;
            int digit = sum %10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            second = second->next;
        }

        while (carry != 0)
        {
            int sum = carry;
            int digit = sum %10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
        }
    } 
    return ansHead;
}


Node* reverse(Node * head){
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* add2LL(Node* first, Node* second){
    //step 1
    first = reverse(first);
    second = reverse(second);

    //step2 adding
    Node* ans = add(first, second);

    // step3 reverse ans
    ans = reverse(ans);

    return ans;
}

//TC=0(M+N), SC=0(max(m,n))