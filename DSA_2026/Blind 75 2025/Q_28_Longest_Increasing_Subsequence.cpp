/*.
300. Longest Increasing Subsequence
Medium
Topics
premium lock icon
Companies
Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

STRIVER VID: https://youtu.be/ekcwMsSIzVc?si=f-ZNA8lhT2IGh-Te
STRIVER SOL: https://takeuforward.org/data-structure/longest-increasing-subsequence-dp-41

*/

/*
Complexity Analysis
Time Complexity: O(n2), where n is the length of the input array. This is because we are using a 2D DP array of size n x n, and each subproblem takes O(1) time to compute.

Space Complexity: O(n2), due to the 2D DP array used to store the results of subproblems. Additionally, the recursion stack can go up to O(n) in depth, but it is dominated by the DP array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to find the length of LIS
    int func(int i, int prevInd, vector<int> &arr, vector<vector<int>> &dp)
    {

        // base case
        if (i == arr.size() - 1)
        {
            if (prevInd == -1 || arr[prevInd] < arr[i])
                return 1;
            return 0;
        }

        // If subproblem is already calculated
        if (dp[i][prevInd + 1] != -1)
            return dp[i][prevInd + 1];

        // Not Take case
        int notTake = func(i + 1, prevInd, arr, dp);

        int take = 0; // Take case

        // If no element is chosen till now
        if (prevInd == -1)
            take = func(i + 1, i, arr, dp) + 1;

        /* Else the current element can be
        taken if it is strictly increasing */
        else if (arr[i] > arr[prevInd])
            take = func(i + 1, i, arr, dp) + 1;

        // Return the maximum length obtained from both cases
        return dp[i][prevInd + 1] = max(take, notTake);
    }

public:
    /* Function to find the longest increasing
    subsequence in the given array */
    int LIS(vector<int> &nums)
    {
        int n = nums.size();

        // DP array
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return func(0, -1, nums, dp);
    }
};

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Creating an object of Solution class
    Solution sol;
    int lengthOfLIS = sol.LIS(nums);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}

// BABBAR VID also check: https://youtu.be/MYHajVcnXSA?si=2dRJ5SaeeXEa64ME
