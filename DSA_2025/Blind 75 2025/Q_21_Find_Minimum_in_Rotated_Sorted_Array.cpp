/*
153. Find Minimum in Rotated Sorted Array
Medium
Topics
premium lock icon
Companies
Hint
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.



Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.


Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

Stiver: https://youtu.be/nhEMDKMB44g?si=PgLrSFLO0a_UQ9jD
Striver code: https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/


*/

//++++++++++++++++++++++++++ Brute Force +++++++++++++++++++++
// Time Complexity: O(N), we check every element once.
// Space Complexity : O(1), constant additonal space is used.
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{

    // Initialize answer with a large number
    int minVal = INT_MAX;

    // Traverse each element
    for (int i = 0; i < nums.size(); i++)
    {

        // Update minimum value
        minVal = min(minVal, nums[i]);
    }

    // Return the result
    return minVal;
}
// PSEUDO CODE OPTIMIZED MORE OPTIMIZE IS BELOW TC=O(LOG N)
int findMinBETTER(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    // Initialize answer with a large number
    int ans = INT_MAX;

    // Traverse-> BINARY SEARCH
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // otpimize addition if search space is already sorted then always the arr[low] is will be smaller and that is going to be the ans always
        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }

        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, nums[mid]);
        }
    }

    // Return the result
    return ans;
}

//+++++++++++++++++++++++++++++++OPTIMAL++++++++++++++++++++++++++++++
// Complexity Analysis
// Time Complexity : O(logN), at every step the search space is reduced to half using binary search.Space Complexity : O(1), constant additonal space is used.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the minimum element using binary search
    int findMin(vector<int> &nums)
    {

        // Initialize low and high pointers
        int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low < high)
        {

            // Calculate mid index
            int mid = low + (high - low) / 2;

            // Check which half to discard
            if (nums[mid] > nums[high])
            {

                // Minimum lies in right half
                low = mid + 1;
            }
            else
            {

                // Minimum lies in left half (including mid)
                high = mid;
            }
        }

        // Return the minimum element
        return nums[low];
    }
};

int main()
{

    // Input array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create object of Solution
    Solution sol;

    // Call function and store result
    int result = sol.findMin(nums);

    // Output the result
    cout << "Minimum element is " << result << endl;

    return 0;
}