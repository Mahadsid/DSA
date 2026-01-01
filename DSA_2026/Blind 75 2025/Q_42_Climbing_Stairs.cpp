/*
70. Climbing Stairs
Easy
Topics
premium lock icon
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

// STRIVER : https://youtu.be/mLfjzJsN8us?si=3ljAhX7uNlZx0Fws
//STRIVER SOL: https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs

*/

/*..
Complexity Analysis

Time Complexity: O(n), since we compute each Fibonacci number from 2 to n exactly once.

Space Complexity: O(n), for storing the DP array of size n+1.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Number for which Fibonacci is to be calculated
    int n = 3;

    // Create a dp array initialized with -1
    vector<int> dp(n + 1, -1);

    // Base cases
    dp[0] = 1;
    dp[1] = 1;

    // Fill dp array using bottom-up dynamic programming
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Print the nth Fibonacci number
    cout << dp[n];
    return 0;
}