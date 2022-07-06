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

// approach create array and copy LL in it and apply logic of palindrome TC=0(N), SC=(N)

bool checkPalindrome(vector<int> arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
    
}

bool ispalindrome(Node* head){
    
    vector<int> arr;
    Node* temp =  head;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp= temp->next;
    }

    return checkPalindrome(arr);
}

// reduce SC  TO -> 0(1)

//approach 2 -> 1.find middle, 2. reverse from middle+1 , 3. compare first and middle+1 
//and so on, 4. reverse middle+1 again to make it same at is at i/p(temporary)
//TC=0(N), sc=0(1)


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


Node* getMid(Node* head){
    
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast ->next != NULL)
    {
        fast = fast->next ->next;
        slow = slow ->next;
    }
    return slow;
}

bool ispalindrome2(Node* head){
    
    if (head==NULL || head->next == NULL)   
    {
        return true;
    }
    //step 1
    Node* middle = getMid(head);
    //step2 
    Node* temp = middle->next;
    middle->next = reverse(temp);
    //step 3
    Node* head1 =  head;
    Node* head2 = middle->next;

    while (head2 != NULL)
    {
        if(head1 -> data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // step 4 
    Node* temp = middle->next;
    middle->next = reverse(temp);

    return true;
}



