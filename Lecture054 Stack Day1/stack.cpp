#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;


//lifo

//implementation of stack using array

class Stack{

    //properties
    int *arr;
    int top;
    int size;

    //functions / behaviours
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size-top>1)
        {
            top++;
            arr[top]= element;
        }
        else{
            cout << "stack overflow" << endl;
        }
        
    } 
    void pop() {
        if (top >= 0)
        {
            top--;
        }
        else{
            cout << "stack underflow" << endl;
        }
    } 
    int peek() {
        if (top >= 0)
        { 
            return arr[top];
        }
        else{
            cout << "stack is empty" << endl;
        }
            
    }  
    bool isEmpty(){
        if (top == -1)
        { 
            return true;
        }
        else
            return false;
    }
        
};// complc =0(1)


int main(){

    stack<int> s;

    s.push(2);
    s.push(4);

    s.pop();

    cout << "printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "stack is empty";
    }
    else
        cout << "stack is not empty";

    

    return 0;
}