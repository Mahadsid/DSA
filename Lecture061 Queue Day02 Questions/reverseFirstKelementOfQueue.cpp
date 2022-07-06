#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

/* 
fetch first k element from queue and & put into stack
fetch element from stack and put into queue
fetch first(n-k) element from Queue and pushback
*/

queue<int> modifyQueue(queue<int> q, int k){
    //step 1
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //step 2
    while (s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    //step 3
    int n = q.size();
    int t = n-k;
    while (t--) 
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
// sc=0(K), tc=0(n)