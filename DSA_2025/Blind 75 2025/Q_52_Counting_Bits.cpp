/*
338. Counting Bits
Easy
Topics
premium lock icon
Companies
Hint
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:

0 <= n <= 105


Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

// code with mik vid= https://youtu.be/uwOz378g3ew?si=DKzp-2zFFdX9Cd6s
// code with mik sol = https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Counting%20Bits.cpp
*/
#include <bits/stdc++.h>
using namespace std;

/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uwOz378g3ew
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/counting-bits/
*/

// Approach-1 (Using built-in function) - __builtin_popcount - O(nlog(n))
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1);

        for (int i = 0; i < n + 1; i++)
        {
            result[i] = __builtin_popcount(i); // log(n)
        }

        return result;
    }
};

// Approach-2 - T.C : O(n)
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1);

        if (n == 0)
            return result;

        result[1] = 1;

        for (int i = 2; i < n + 1; i++)
        {

            if (i % 2 == 0)
            {
                result[i] = result[i / 2];
            }
            else
            {
                result[i] = result[i / 2] + 1;
            }
        }

        return result;
    }
};