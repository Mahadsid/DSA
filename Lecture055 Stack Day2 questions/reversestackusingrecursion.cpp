#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

/* algo-> 1. stack ke top elem ko side m rakh lo
2. use recurssion to solve remainig part 
3. wapas ate hue top ko insert at bottom krdena  */


void insertAtBottom(stack<int> &stack, int element){
    //base case 
    if(stack.empty()){
        stack.push(element);
        return;
    }

    int num = stack.top();
    stack.pop();

    //next recussive call

    insertAtBottom(stack, element);

    stack.push(num);


}

void reverseStack(stack<int> &stack){
    //base case 
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, num);
}