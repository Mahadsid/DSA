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

Node* sort(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    
    

    while (temp != NULL)
    {
        if (temp ->data == 0)
        {
            zeroCount++;
        }
        else if(temp ->data == 1){
            oneCount++;
        }
        else if(temp ->data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp ->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp ->data = 0;
            oneCount--;
        }
        else if(twoCount != 0){
            temp ->data = 0;
            twoCount--;
        }
        temp = temp -> next;
    }
    

    return head;
}
//tc=0(N) sc=0(1)

//approach two (if data replacement is not allowed  or   change links only)
//make link list = no of data then merege them


void populate(Node* &tail, Node* curr){

    tail->next =curr;
    tail = curr;
}

Node* sort2(Node* head){
    if(head == NULL) {
        cout << "List is Empty "<< endl;
        return NULL;
    }

    

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;


    Node* curr = head;
    //created 3 link list

    while (curr != NULL)
    {
        int value = curr -> data;
        if (value == 0)
        {
            populate(zeroTail, curr);
        }
        else if(value == 1){
            populate(oneTail, curr);
        }
        else if(value == 2){
            populate(twoTail, curr);
        }
        curr = curr -> next;
    }
  // merge krdo y 3 link list

  // 1 ki list is non empty
  if (oneHead ->next != NULL)
  {
    zeroTail -> next = oneHead ->next;
  }
  else{
    zeroTail -> next = twoHead ->next;
  }
  oneTail ->next = twoHead->next;
  twoTail ->next = NULL;

  head = zeroHead ->next;

  //delete dummy nodes
  delete zeroHead;
  delete oneHead;
  delete twoHead;

    return head;
}// TC = 0(n) sc=0(1)
