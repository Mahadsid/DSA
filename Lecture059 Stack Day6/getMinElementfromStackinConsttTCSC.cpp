#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;


/* algo push -> 2* curr - mini
        pop  -> 2* mini - curr
        getmin(mini)
*/


class SpecialStack{

    //define the data members.
    stack<int> s;
    int mini =  INT_MAX;

    void push(int data){
        // for first element
        if((s.empty())){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                s.push(2 * data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }

    }

    int pop(){
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if (curr > mini)
        {
            return curr;
        }
        else{
            int prevMIn = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMIn;
        }
    }

    int top(){
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();

        if (curr < mini)
        {
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){
        if (s.empty())
        {
            return -1;
        }

        return mini;
    }
};