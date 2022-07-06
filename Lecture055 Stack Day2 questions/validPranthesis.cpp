#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;


bool matches(char top, char ch){
    if (  (ch == '}' && top == '{') ||
        (ch == ']' && top == '[') ||
        (ch == ')' && top == '(') )
    {
        return true;
    }
    else
        return false; 
}

bool isvalidParenthesis(string expression){
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if opening brackect , stack push

        if (ch == '{' || ch == '(' || ch == '[' )
        {
            s.push(ch);
        }

        else{// for close bracket , stacktop check and pop
            if (!s.empty())
            {
                char top = s.top();

                if(matches(top, ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false; //unbalanced expression
            }
        }
        
    }

    if (s.empty())
    {
        return true;
    }
    else{
        return false;
    }
    
}