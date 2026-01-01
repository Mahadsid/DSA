/*
53. Maximum Subarray
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

STRIVER VID: https://youtu.be/AHZpyENo7k4?si=7c9idPGqezkkJxcy
STRIVER SOL: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array
*/

#include <bits/stdc++.h>
using namespace std;

//+++++++++++++++++++++++++++++++++++ BRUTE FORCE+++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N^3), where N is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.

Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.
*/
int maxSubArray(vector<int> &nums)
{

    /* Initialize maximum sum with
    the smallest possible integer*/
    int maxi = INT_MIN;

    // Iterate over each starting index of subarrays
    for (int i = 0; i < nums.size(); i++)
    {

        /* Iterate over each ending index
        of subarrays starting from i*/
        for (int j = i; j < nums.size(); j++)
        {

            // Variable to store the sum of the current subarray
            int sum = 0;

            // Calculate the sum of subarray nums[i...j]
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }

            /* Update maxi with the maximum of its current
            value and the sum of the current subarray*/
            maxi = max(maxi, sum);
        }
    }

    // Return the maximum subarray sum found
    return maxi;
}

//+++++++++++++++++++++++++++++++++++++++++++ BETTER SOL ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N^2), where N is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index of the subarray.

Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.
*/
int maxSubArray(vector<int> &nums)
{

    /* Initialize maximum sum with
    the smallest possible integer*/
    int maxi = INT_MIN;

    // Iterate over each starting index of subarrays
    for (int i = 0; i < nums.size(); i++)
    {

        /* Variable to store the sum
        of the current subarray*/
        int sum = 0;

        /* Iterate over each ending index
        of subarrays starting from i*/
        for (int j = i; j < nums.size(); j++)
        {

            /* Add the current element nums[j] to
            the sum i.e. sum of nums[i...j-1]*/
            sum += nums[j];

            /* Update maxi with the maximum of its current
            value and the sum of the current subarray*/
            maxi = max(maxi, sum);
        }
    }

    // Return the maximum subarray sum found
    return maxi;
}

//+++++++++++++++++++++++++++++++++++++++++++++ OPTIMAL SOL +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.

Space Complexity: O(1). We use a constant amount of space for variables.
*/
class Solution
{
public:
    // Function to find maximum sum of subarrays
    int maxSubArray(vector<int> &nums)
    {

        // maximum sum
        long long maxi = LLONG_MIN;

        // current sum of subarray
        long long sum = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {

            // Add current element to the sum
            sum += nums[i];

            // Update maxi if current sum is greater
            if (sum > maxi)
            {
                maxi = sum;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0)
            {
                sum = 0;
            }
        }

        // Return the maximum subarray sum found
        return maxi;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++ FOLLOW UP: PRINT THE SUBARRAY WHICH GIVE THE MAXIMUM SUM ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.

Space Complexity: O(1). We use a constant amount of space for variables.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int> &nums)
    {

        // maximum sum
        long long maxi = LLONG_MIN;

        // current sum of subarray
        long long sum = 0;

        // starting index of current subarray
        int start = 0;

        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {

            // update starting index if sum is reset
            if (sum == 0)
            {
                start = i;
            }

            // add current element to the sum
            sum += nums[i];

            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > maxi)
            {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0)
            {
                sum = 0;
            }
        }

        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;

        // Return the maximum subarray sum found
        return maxi;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Create an instance of Solution class
    Solution1 sol;

    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}