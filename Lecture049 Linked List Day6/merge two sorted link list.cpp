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
// approach 1 kya second ka data first k do element k bich m askta h?

Node* solve(Node* first,Node* second){

    //if only one element present in first LL
    if (first ->next == NULL)
    {
        first->next = second;
        return first;
    }
    

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2 -> data >= curr1 ->data) && (curr2 -> data <= next1 ->data))
        {
            // adding node to right position by updating pointers
            curr1 ->next = curr2;
            next2 = curr2->next;
            curr2->next= next1;

            //updating pointers for next check
            curr1 = curr2;
            curr2 = next2;

        }
        else{
            //data range m lie ni krta to pointers ko aaghe badao curr1 nad next1 ko bdhao
            
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL){//first link empty hogyi h ab bachi hui second chipka do
                curr1->next = curr2;
                return first;
            } 
            
        }
        
    }
    return first;
    
}

Node* twosortedmerge(Node* first,Node* second){
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    if (first -> data <= second ->data)
    {
       return solve(first, second);
    }
    else{
      return  solve(second, first);
    }
    return first;
}

//TC=0(n) SC=0(1)