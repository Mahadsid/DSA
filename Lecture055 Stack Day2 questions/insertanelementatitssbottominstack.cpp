#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

void solve(stack<int> & inputStack, int element){

    //base case
    if(inputStack.empty()){
        inputStack.push(element);
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    //next recussive call

    solve(inputStack, element);

    inputStack.push(num);

}

stack<int> pushAtBottom(stack<int> &myStack, int x){
    
    solve(myStack, x);
    return myStack;
}