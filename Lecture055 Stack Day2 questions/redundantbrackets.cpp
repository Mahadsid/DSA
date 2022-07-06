#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;


//tc=0(n)

bool findRedundantBrackets(string &s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // if opening brackect , stack push

        if ( ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' )
        {
            st.push(ch);
        }

        else{// for close bracket or lowercase letter, stacktop check and pop
            if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() !=  '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/' ){
                        isRedundant = false;

                    }
                    st.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                }
                st.pop();      
            }  
        }    
    }
    return false;  
}