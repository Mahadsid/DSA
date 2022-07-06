#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


//TC =0(n), sc =0(n)
queue<int> reverse(queue<int> q){
    stack<int> s;
    while (!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
 
}