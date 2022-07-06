#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

string FirstNonRepeating(string A){
    
    map<char, int> count;
    queue<int> q;
    string ans="";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // count inc
        count[ch]++;
        //push it in queue
        q.push(ch);

        while (!q.empty())
        {
            if(count[q.front()] > 1){
                //repeating char
                q.pop();
            }
            else{
                //non repeating
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}