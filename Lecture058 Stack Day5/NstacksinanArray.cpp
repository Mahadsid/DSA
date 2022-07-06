#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

// x->data , m -> konsi stack 
//drawback of 2 stack approach in k stack ->  no space optimization 

/*approach 2
*/

class NStack{

    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;


    // itialize ur data sturct
    NStack(int N, int S){
        n= N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //top initialaize
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        //next initialaize
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        // update next index to -1
        next[s-1] = -1;

        freespot=0;
    }

    bool push(int x, int m){

        // check for overflow
        if (freespot == -1)
        {
            return false;
        }
        
        //find index
        int index = freespot;

        // update freespot
        freespot = next[index];
        
        //insert element
        arr[index] = x;
        
        //update next
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;

        return true;
    }

    int pop(int m){ //reverse of push

        //check underflow

        if (top[m-1] == -1)
        {
            return -1;
        }

        int  index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

//TC=0(1), SC=0(s+n)