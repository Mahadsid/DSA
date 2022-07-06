#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;


/* COND^N 1. every one knows cleberity (vertical / col -> will be all one except diagonal)
COND^N    2. but celebirty knows no one (row will be zero ) 


algo -> put all elemnts in stack
jab tak satck size != 1
{
    do element nikal lo s.top(), s.pop() kr lo do bar a, b
    if a knows b{
    discard a , push b(hoskat h celeb)
    }
    if b knows a{
    discar b, push a(ho skta h celeb)
    }

    ab jo ek stack m candidate bcha hua h wo ek potential candidate h

    verify krlo fir wo do condition 
}
*/

bool knows(vector<vector<int>> &M, int a, int b, int n){
    if (M[a][b]==1)
    {
        return true;
    }
    else
        return false;
    
}


int celebrity(vector<vector<int>> &M, int n){
    stack<int> s;

    //step 1 push all element in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    //step 2

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(M, a, b, n))
        {
            s.push(b);
        }
        else    
        {
            s.push(a);
        }    
    }
    // ek potential celebrity -> verify krlo
    int candidate = s.top();

    bool rowCheck = false;
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zerocount++;
        }
    }
    if (zerocount == n)
    {
        rowCheck = true;
    }

    bool colCheck = false;
    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
        {
            onecount++;
        }
    }
    if (onecount == n-1)
    {
        colCheck = true;
    }
    

    if (colCheck ==  true && colCheck == true)
    {
        return candidate;
    }
    else
        return -1;
    
    return candidate;
}

