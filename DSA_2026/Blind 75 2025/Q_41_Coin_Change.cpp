/*
322. Coin Change OR MINIMUM COINS
Medium
Topics
premium lock icon
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

// STRIVER VID: https://youtu.be/myPeWb3Y68A?si=NBHIhBZHh51PvLsg
// STRIVER SOL: https://takeuforward.org/data-structure/minimum-coins-dp-20

*/

#include <bits/stdc++.h>
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++ MEMOIZATION +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N*T), there are total of N*T states.
Space Complexity: O(N*T) + O(N), additonal space used to for memo table and recursion stack.
*/
#include <bits/stdc++.h>
using namespace std;

// Solution class to implement memoization approach
class Solution2
{
public:
    // Function to find minimum coins
    int coinChange(vector<int> &coins, int amount)
    {
        // Creating dp array initialized with -2
        // (-2 means not calculated yet)
        vector<int> dp(amount + 1, -2);

        // Calling helper function
        return helper(coins, amount, dp);
    }

private:
    // Helper recursive function
    int helper(vector<int> &coins, int rem, vector<int> &dp)
    {
        // If remaining amount is zero
        if (rem == 0)
            return 0;

        // If remaining amount is negative
        if (rem < 0)
            return -1;

        // If already computed
        if (dp[rem] != -2)
            return dp[rem];

        // Initialize minimum with large value
        int mini = INT_MAX;

        // Try every coin
        for (int coin : coins)
        {
            // Recursive call
            int res = helper(coins, rem - coin, dp);

            // If result is valid
            if (res >= 0 && res < mini)
                mini = 1 + res;
        }

        // Store result in dp
        dp[rem] = (mini == INT_MAX) ? -1 : mini;
        return dp[rem];
    }
};

// Driver function
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution2 obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++ TABULATION++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N*T), there are total of N*T states.
Space Complexity: O(N*T), additonal space used to for memo table.
*/
#include <bits/stdc++.h>
using namespace std;

// Solution class to implement tabulation approach
class Solution1
{
public:
    // Function to find minimum coins
    int coinChange(vector<int> &coins, int amount)
    {
        // Creating dp array of size amount+1
        vector<int> dp(amount + 1, INT_MAX);

        // Base case: dp[0] = 0
        dp[0] = 0;

        // Loop through all amounts from 1 to amount
        for (int i = 1; i <= amount; i++)
        {
            // Try each coin
            for (int coin : coins)
            {
                // If coin can be used
                if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                {
                    // Update dp[i] with minimum coins
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still infinity, return -1
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// Driver function
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution1 obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}

//++++++++++++++++++++++++++++++++++++++ SPACE OPTIMIZATION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N*T), there are total of N*T states.
Space Complexity: O(T), additonal space used to for storing rows.
*/
#include <bits/stdc++.h>
using namespace std;

// Class containing the solution method
class Solution
{
public:
    // Function to compute minimum elements to reach target sum
    int minimumElements(vector<int> &arr, int T)
    {
        int n = arr.size();

        // Create two vectors for previous and current rows
        vector<int> prev(T + 1, 0);
        vector<int> cur(T + 1, 0);

        // Initialize base case for the first row
        for (int i = 0; i <= T; i++)
        {
            if (i % arr[0] == 0)
                prev[i] = i / arr[0];
            // Very large value if not possible
            else
                prev[i] = 1e9;
        }

        // Fill table using bottom-up approach
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= T; target++)
            {

                // Option 1: Not take the current element
                int notTake = prev[target];

                // Option 2: Take the current element if possible
                int take = 1e9;
                if (arr[ind] <= target)
                    take = 1 + cur[target - arr[ind]];

                // Store minimum of take and notTake
                cur[target] = min(notTake, take);
            }

            // Update previous row with current row values
            prev = cur;
        }

        // Retrieve answer from the last row
        int ans = prev[T];

        // Return -1 if target cannot be formed
        if (ans >= 1e9)
            return -1;

        // Return minimum number of elements required
        return ans;
    }
};

// Main function to test the solution
int main()
{

    // Input array
    vector<int> arr = {1, 2, 3};

    // Target sum
    int T = 7;

    // Create object of Solution class
    Solution sol;

    // Call function to get result
    int result = sol.minimumElements(arr, T);

    // Output the result
    cout << "The minimum number of coins required to form the target sum is "
         << result << endl;

    // Return 0 to indicate successful execution
    return 0;
}