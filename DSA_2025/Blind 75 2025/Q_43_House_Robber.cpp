/*
198. House Robber
Medium
Topics
premium lock icon
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/
/*
Complexity Analysis

Time Complexity: O(n), where n is the number of houses. We process each house once in two separate passes (excluding first and last), but each pass is linear.

Space Complexity: O(1), since only constant extra space is used for variables like prev and prev2; no additional DP array is maintained.


// STRIVER VID: https://youtu.be/GrMBfJNk_NY?si=H9kOTzNAEphuMzZm
// STRIVER SOL: https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6
*/

#include <bits/stdc++.h>
using namespace std;

// Function to solve the linear house robber problem (no circular arrangement)
long long int solve(vector<int> &arr)
{
    // Get the size of the array
    int n = arr.size();

    // If there's only one house, return its value
    if (n == 1)
        return arr[0];

    // prev stores the maximum sum till the previous index
    long long int prev = arr[0];

    // prev2 stores the maximum sum till the index before previous
    long long int prev2 = 0;

    // Loop through houses starting from index 1
    for (int i = 1; i < n; i++)
    {
        // Option 1: Pick the current house and add the value from prev2
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;

        // Option 2: Skip the current house, take prev
        long long int nonPick = prev;

        // Choose the maximum of pick and nonPick
        long long int cur_i = max(pick, nonPick);

        // Update prev2 and prev for the next iteration
        prev2 = prev;
        prev = cur_i;
    }
    // prev will contain the maximum loot possible
    return prev;
}

// Function to solve the circular house robber problem
long long int robStreet(int n, vector<int> &arr)
{
    // If there are no houses, return 0
    if (n == 0)
        return 0;

    // If there is only one house, return its value
    if (n == 1)
        return arr[0];

    // Create two arrays:
    // arr1 excludes the first house
    // arr2 excludes the last house
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr1.push_back(arr[i]);
        if (i != n - 1)
            arr2.push_back(arr[i]);
    }

    // Compute maximum loot for both cases and return the maximum
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    return max(ans1, ans2);
}

// Driver code
int main()
{
    // Example input
    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();

    // Output the maximum loot possible
    cout << robStreet(n, arr);
    return 0;
}