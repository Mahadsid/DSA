/*
76. Minimum Window Substring
Hard
Topics
premium lock icon
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?

//STRIVER VID: https://youtu.be/WJaij9ffOIY?si=7RlFRku7lzoQPmXp
//STRIVER SOL:
*/

// github sol TC: O(2N) + O(M), SC=O(256) if all char are given
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int i = 0;
        int j = 0;
        int min_len = INT_MAX;
        int ans = -1;
        unordered_map<char, int> m1, m2;
        int k = 0;
        for (auto ch : t)
        {
            m2[ch]++;
        }
        int n = m2.size();
        while (j < m)
        {
            if (m2.count(s[j]))
            {
                m1[s[j]]++;
                if (m1[s[j]] == m2[s[j]])
                {
                    ++k;
                }
            }
            while (k == n)
            {
                if (j - i + 1 <= min_len)
                {
                    min_len = j - i + 1;
                    ans = i;
                }
                if (m1.count(s[i]))
                {
                    m1[s[i]]--;
                    if (m2[s[i]] > m1[s[i]])
                    {
                        --k;
                    }
                }
                ++i;
            }
            ++j;
        }
        return ans == -1 ? "" : s.substr(ans, min_len);
    }
};

// some github sol
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for (char c : t)
        {
            ++need[c];
        }

        int m = s.length(), n = t.length();
        int k = -1, mi = m + 1, cnt = 0;

        for (int l = 0, r = 0; r < m; ++r)
        {
            char c = s[r];
            if (++window[c] <= need[c])
            {
                ++cnt;
            }

            while (cnt == n)
            {
                if (r - l + 1 < mi)
                {
                    mi = r - l + 1;
                    k = l;
                }

                c = s[l];
                if (window[c] <= need[c])
                {
                    --cnt;
                }
                --window[c];
                ++l;
            }
        }

        return k < 0 ? "" : s.substr(k, mi);
    }
};