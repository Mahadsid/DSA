/*
5. Longest Palindromic Substring
Medium
Hint
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
https://youtu.be/6i_T5kkfv4A?si=63ioAWv0Cuah08KM

https://takeuforward.org/data-structure/longest-palindromic-substring

Time Complexity: O(N²) For each character, expanding could take up to O(N)

Space Complexity: O(1) No extra space used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string str)
    {
        int start = 0, end = 0;

        // Iterate through each character as center
        for (int center = 0; center < str.length(); center++)
        {
            // Expand around odd length palindrome
            int lenOdd = expandFromCenter(str, center, center);
            // Expand around even length palindrome
            int lenEven = expandFromCenter(str, center, center + 1);
            // Get the max of both lengths
            int maxLen = max(lenOdd, lenEven);

            // Update the longest palindrome boundaries
            if (maxLen > end - start)
            {
                start = center - (maxLen - 1) / 2;
                end = center + maxLen / 2;
            }
        }

        // Return the longest palindromic substring
        return str.substr(start, end - start + 1);
    }

private:
    int expandFromCenter(const string &str, int left, int right)
    {
        // Expand while characters match and within bounds
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};

int main()
{
    Solution sol;
    string input = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input) << endl;
    return 0;
}