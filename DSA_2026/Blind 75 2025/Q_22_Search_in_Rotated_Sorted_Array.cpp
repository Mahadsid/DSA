/*
33. Search in Rotated Sorted Array
Medium
Topics
premium lock icon
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

strive:https://youtu.be/5qGrJbHhqFs?si=tM_XQrQazvyEwZsE
striver code:https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/

*/
#include <bits/stdc++.h>
using namespace std;

// ++++++++++++++++++++++ BRUTE FORCE ++++++++++++++++++++++++++++
/*
Time Complexity: O(N),We may need to check every element in the worst case if the target is not present.

Space Complexity: O(1),No extra space is used; only constant variables.
*/
int search(vector<int> &nums, int target)
{

    // Loop through each element in the array
    for (int i = 0; i < nums.size(); i++)
    {

        // If current element matches target, return index
        if (nums[i] == target)
        {
            return i;
        }
    }

    // If not found, return -1
    return -1;
}

//+++++++++++++++++++++++++++++++++++++ OPTIMAL+++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.

Space Complexity: O(1),We use only a few variables (low, high, mid) no extra space used.
*/
class Solution
{
public:
    // Function to search for target using binary search in rotated sorted array
    int search(vector<int> &nums, int target)
    {

        // Set the search space to entire array
        int low = 0;
        int high = nums.size() - 1;

        // Continue until the search space becomes invalid
        while (low <= high)
        {

            // Find the middle index
            int mid = (low + high) / 2;

            // If the target is found at mid, return mid
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid])
            {

                // If target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                // Else search in the right half
                else
                {
                    low = mid + 1;
                }
            }

            // Otherwise, right half is sorted
            else
            {

                // If target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                // Else search in the left half
                else
                {
                    high = mid - 1;
                }
            }
        }

        // If not found, return -1
        return -1;
    }
};

// Driver code
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution obj;
    int result = obj.search(nums, target);

    cout << result << endl;

    return 0;
}