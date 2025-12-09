/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

NeetCode: https://youtu.be/4RACzI5-du8?si=JwjFmYg4QgNMEjB6
C++:
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

int countPalindromes(string s, int left, int right)
{
    int count = 0;
    while (left >= 0 && right < s.length() && s[left] == s[right]) // checking for palindrome at every character if yes inc count.
    {
        count++;
        left--;
        right++;
    }
    return count;
}

int countSubstrings(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++) // at every char in string take that as a center and check plaindrome outside(left & right)side of it for odd case it works, for even case take two char and check outside from then.
    {
        // count palindrome with odd length
        count += countPalindromes(s, i, i); // for odd case left and right point at same position/char so i, i

        // count plaindrome with even length
        count += countPalindromes(s, i, i + 1); // for even case we take two char one at left/i and one next to left i.e right/i+1
    }
    return count;
}

int main()
{
    string s = "aaa";

    cout << endl;
    cout << countSubstrings(s) << endl;

    return 0;
}