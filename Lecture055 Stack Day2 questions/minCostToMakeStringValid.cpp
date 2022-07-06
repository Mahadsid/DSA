#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

/* logic -> if str length is odd -> return -1 (bcz no of open brck = no of close)
i/p -> remove valid string
a -> count of closed braces
b-> count of open braces

for all open even -> b/2
for all closed even -> a/2

half close, half open }}} {{{ -> anns =4
}}}}{{{{ -> ans = 4

so expression = ((a+1)/2)+((b+1)/2)

*/

int findMinCost(string str){

    //odd condition

    if(str.length()%2 == 1){
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if ( ch == '{'  )
        {
            s.push(ch);
        }
        else{
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else{
                s.push(ch);
            }
            
        }
    }
    
    int a =0, b=0;
    while (!s.empty())
    {
        if(s.top() == '{'){
            b++;
        }
        else{
            a++; 
        }
        s.pop();
    }

    int ans = (a+1)/2+(b+1)/2;

    return ans;

}