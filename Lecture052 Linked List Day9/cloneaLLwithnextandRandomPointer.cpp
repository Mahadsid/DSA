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

//random ptr given 1->3, 3->5, 5->2, 2->1
/* approch step 1 = create a clone list (using next ptr of original list)
step2 = random pointer copy using clone->random = mapping[original->random]
TC=0(N) SC=0(N) BCZ of map
*/
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


Node* copyList(Node* head){
    //step 1 create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead,cloneTail, temp->data);
        temp = temp->next;
    }

    //step 2 create a map
    map<Node*, Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode ->next;
        cloneNode = cloneNode ->next;
    }
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode-> random = oldToNewNode[originalNode->random];
        originalNode = originalNode ->next;
        cloneNode = cloneNode ->next;
    }
    return cloneHead;
    
    

}// TC=0(N) SC=0(N)


//approach 2 optimise space to 0(1) (pointer/links change krro,)
Node* copyList2(Node* head){

    //step1: create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    

    //step2: clonne node add in b/w original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode ->next;
        originalNode->next = cloneNode;
        originalNode = next;

        //same step for clone LL
        next = cloneNode->next;
        cloneNode ->next = originalNode;
        cloneNode = next;
    }
    //step3: random pointer copy

    temp = head;
    while(temp != NULL){
        if(temp -> next != NULL){
            if (temp -> random != NULL)
            {
                temp ->next ->random = temp -> random ->next;

            }
            else{
                temp-> next = temp -> random;
            }
            // using one line only = use tertianary condition
            //temp ->next ->random = temp -> random ? temp -> random ->next : temp -> random
        }
        temp = temp ->next-> next;  
    }

    //step4: revert changes in step2 
    originalNode =head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode ->next = cloneNode -> next;
        originalNode = originalNode ->next;

        if (originalNode != NULL)
        {
            cloneNode ->next = originalNode ->next;
        }
        cloneNode =  cloneNode->next;
    }


    //step5: return ans
    return cloneHead;
}
//TC=0(N), SC=0(1)