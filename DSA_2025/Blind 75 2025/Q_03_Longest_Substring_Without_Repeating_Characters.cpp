/*
3. Longest Substring Without Repeating Characters
Hint
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

https://youtu.be/-zSxTJkcdAo?si=TBqH9EC2E_XtQy0f
*/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// ++++++++++++++++++++ Brute Force ++++++++++++++
/*
 Generate all possible combinations/ genertrate all sub string with each charater in a string.
 Pseudo code
 max_len = 0
 for(i=o to n){
    sub_str = ""
    hash[255] = {0} //for keep track if we get repeating char
    for(j=i to n){
        if(hash[s[j]] == 1) break; //if we found repeating char skip it.
        sub_str = sub_Str + org_str[i];
        len = j - i + 1;
        max_len = max(max_len, len);
        hash[s[j] = 1]; // to put char into hash, so if it again comes we can say we saw it.
    }
 }
    return max_len
    TC: 0(N^2)
    SC:O(256)

*/

//+++++++++++++++ Better Sliding window/ 2 pointer +++++++++++++
/*
    TC:O(N), SC:O(256)
*/
int LongestSubstringWORepeat(string s)
{
    // CHECK VIDEO ITS GREAT EXPLANATION
    if (s.size() == 0)
        return 0;
    int l = 0;
    int r = 0;
    int maxi = 0;
    int n = s.size();
    unordered_map<char, int> mp;
    while (r < n)
    {
        if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) // condn says when checking for char, if we find it in hash ok, but && means both should be true, the other cond says  the seen position should be greater than previous seen so we move left pointer,
        {
            l = mp[s[r]] + 1;
        }
        maxi = max(maxi, r - l + 1); // max(maxi, len)
        mp[s[r]] = r;                // update position of char, regardless
        r++;                         // slide window
    }
    return maxi;
}

// ANOTER way to solve but check above sol its clear.
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> freq;
    int maxlen = 0;
    int l = 0, r = 0;
    int n = s.size();
    while (r < n)
    {
        freq[s[r]]++;
        // shrinking when duplicate is found
        while (freq[s[r]] > 1)
        {
            freq[s[l]]--;
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{

    string s = "cadbzabcd";
    cout << endl;
    cout << LongestSubstringWORepeat(s) << endl;
    cout << endl;

    return 0;
}