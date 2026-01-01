/*

Code
Testcase
Test Result
Test Result
20. Valid Parentheses
Easy
Topics
premium lock icon
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false



Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

NeetCode: https://youtu.be/WTzjTskDFMg?si=T9uZDoVSim9jbNU4
C++: https://youtu.be/9fk5yZna2Bk?si=z8LRTzAfujV1jWUs
*/
#include <bits/stdc++.h>
using namespace std;

// c++ Solution
bool ismatching(char a, char b)
{
    return ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')')); // matching stack top and closing
}
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        // Start pushing opening bracket in stack
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            // if stack is emtpty bcz sting is null so return false
            if (st.empty())
            {
                return false;
            }
            if (ismatching(st.top(), s[i]))
            {
                st.top(); // match stack top and closing bracket if equal then return true else false
            }
            else
            {
                return false; // else fasle
            }
        }
    }
    if (st.empty())
    {
        return true; // if we successfully match and stack become empty so return true.
    }
    else
    {
        return false; // if there are uneven brackets so stack gonna remain non-empty so return false.
    }
}

// STRIVER VERSION
#include <bits/stdc++.h>
using namespace std;

// Class containing the isValid method
class Solution
{
public:
    // Function to check if the input string has valid parentheses
    bool isValid(string s)
    {
        stack<char> st; // Stack to store opening brackets

        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
                st.push(it); // Push opening brackets to stack
            else
            {
                if (st.empty())
                    return false; // No matching opening bracket
                char ch = st.top();
                st.pop();

                // Check for matching pair
                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty(); // True if all brackets matched
    }
};

int main()
{
    Solution sol;
    string s = "()[{}()]";

    if (sol.isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

// algo moster code
class Solution
{
public:
    /**
     * Validates if the input string contains valid parentheses.
     * A string is valid if:
     * - Open brackets are closed by the same type of brackets
     * - Open brackets are closed in the correct order
     * - Every close bracket has a corresponding open bracket
     *
     * @param s Input string containing only '(', ')', '{', '}', '[', ']'
     * @return true if the string is valid, false otherwise
     */
    bool isValid(string s)
    {
        // Use string as a stack to store opening brackets
        string stack;

        // Iterate through each character in the input string
        for (char current_char : s)
        {
            // If current character is an opening bracket, push it onto the stack
            if (current_char == '(' || current_char == '{' || current_char == '[')
            {
                stack.push_back(current_char);
            }
            // If it's a closing bracket
            else if (stack.empty() || !isMatchingPair(stack.back(), current_char))
            {
                // Stack is empty (no matching opening bracket) or
                // brackets don't match - return false
                return false;
            }
            else
            {
                // Valid matching pair found, remove the opening bracket from stack
                stack.pop_back();
            }
        }

        // Valid only if all opening brackets have been matched (stack is empty)
        return stack.empty();
    }

private:
    /**
     * Checks if the given left and right brackets form a matching pair.
     *
     * @param left_bracket The opening bracket character
     * @param right_bracket The closing bracket character
     * @return true if they form a valid pair, false otherwise
     */
    bool isMatchingPair(char left_bracket, char right_bracket)
    {
        return (left_bracket == '(' && right_bracket == ')') ||
               (left_bracket == '[' && right_bracket == ']') ||
               (left_bracket == '{' && right_bracket == '}');
    }
};