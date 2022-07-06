#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;


//lifo

//implementation of stack using array

class TwoStack{

    //properties
    int *arr;
    int top1;
    int top2;
    int size;

    //functions / behaviours
    TwoStack(int size){
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int num) {
        if (top2-top1 > 1)//at least ek empty space available h
        {
            top1++;
            arr[top1] = num;
        }
        else{
            cout << "stack overflow" << endl;
        }
        
    } 
    void push2(int num) {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
        else{
            cout << "stack overflow" << endl;
        }
        
    } 
    int pop1() {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            cout << "stack underflow" << endl;
            return -1;
        }
    } 
    int pop2() {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            cout << "stack underflow" << endl;
            return -1;
        }
    } 
    /*int peek() {
        if (top1 > 0)
        { 
            return arr[top1];
        }
        else{
            cout << "stack is empty" << endl;
        }
            
    }  
    bool isEmpty(){
        if (top1 == -1)
        { 
            return true;
        }
        else
            return false;
    }*/
        
};