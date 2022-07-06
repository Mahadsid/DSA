#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

//d0nt use loops
/*i/p->  3      o/p-> 9
        -7            5
         9            3
        -2           -2
         5           -7
*/
//tc=0(n"2)

void sortdedInsert(stack<int> &stack, int element){
    //base case 
    if( stack.empty() || (stack.empty() && stack.top() <  element) ){
        stack.push(element);
        return;
    }

    int num = stack.top();
    stack.pop();

    //next recussive call

    sortdedInsert(stack, element);

    stack.push(num);


}

void sortStack(stack<int> &stack){
    //base case 
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortdedInsert(stack, num);

}