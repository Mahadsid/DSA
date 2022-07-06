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

//approach 1 get length & mid= len/2 odd = len/2 even = len/2  (for position = len/2 +1) TC=0(N)

int getLength(Node* head){
    int len =0;
    while(head != NULL){
        len++;
        head = head-> next;
    }
    return len;
}

Node * FindMiddle(Node * head){
    int len = getLength(head);
    int ans = (len/2);

    Node* temp = head;
    int cnt=0;
    while (cnt< ans)
    {
        temp = temp->next;
        cnt++;
    }
    
    return temp;
}

// Approach 2 optimised( two kheladi) TC=0(N), SC=0(1)
Node * GetMiddle(Node * head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    if (head -> next -> next =NULL)     
    {
        return head-> next;
    }
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL)
    {
        fast= fast -> next;
        if(fast != NULL){
            fast= fast -> next;
        }
        slow= slow -> next;
    }
    return slow;

}