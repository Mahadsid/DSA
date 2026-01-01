/*
91. Decode Ways
Medium
Topics
premium lock icon
Companies
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"

Output: 3

Explanation:

"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"

Output: 0

Explanation:

"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.



Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HW-y3gvQTVQ
    Company Tags                : Facebook, Uber, Google, Facebook, Microsoft
    Leetcode Link               : https://leetcode.com/problems/decode-ways/
    Four approaches             : Memoized, Top Down, Better Top Down, O(1) space DP
*/

#include <bits/stdc++.h>
using namespace std;

/************************************************************************ C++ ***************************************************************/
// Approach-1 (Using Recursion + Memoization)
// T.C : O(n) after memoization (without memoization - O(2^n)
// S.C : O(101) ~= O(1)
class Solution
{
public:
    int t[101];
    int solve(int i, string &s, int &n)
    {
        if (t[i] != -1)
        {
            return t[i];
        }

        if (i == n)
        {
            return t[i] = 1; // one valid split done
        }

        if (s[i] == '0')
        {
            return t[i] = 0; // not possible to split
        }

        int result = solve(i + 1, s, n);

        if (i + 1 < n)
        {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                result += solve(i + 2, s, n);
        }

        return t[i] = result;
    }

    int numDecodings(string s)
    {
        int n = s.length();

        memset(t, -1, sizeof(t));
        return solve(0, s, n);
    }
};

// Approach-2 (Bottom Up Way-1)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    int bottom_up_1(string &s, int n)
    {
        // simply simulate the memoized version
        vector<int> t(n + 1, 0);
        // t[i] = ways to decode string from index i to n
        t[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                t[i] = 0;
            else
            {
                t[i] = t[i + 1];
                if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    t[i] += t[i + 2];
            }
        }
        return t[0];
    }

    int numDecodings(string &s)
    {
        int n = s.length();
        vector<int> t(n + 1, -1);
        return bottom_up_1(s, n);
    }
};

// Approach-3 (Using Bottom Up Way-2)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    int bottom_up_2(string &s, int n)
    {
        vector<int> t(n + 1, 0);
        // t[i] = ways to decode string of length i
        t[0] = 1;
        t[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                t[i] += t[i - 1];

            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
                t[i] += t[i - 2];
        }
        return t[n];
    }

    int numDecodings(string &s)
    {
        int n = s.length();
        vector<int> t(n + 1, -1);
        return bottom_up_2(s, n);
    }
};

// Approach-4
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 1)
            return s[0] == '0' ? 0 : 1;
        if (s[0] == '0')
            return 0;

        int last1 = 1, last2 = 1;

        for (int i = 1; i < n; i++)
        {
            int count = s[i] != '0' ? last1 : 0;

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                count += last2;

            last2 = last1;
            last1 = count;
        }

        return last1;
    }
};
