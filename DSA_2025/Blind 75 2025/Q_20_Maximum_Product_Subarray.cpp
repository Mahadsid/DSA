// ++++++++++++++++++++++++++++++ STRIVER ++++++++++++++++++++++++++++++++
// https://youtu.be/hnswaLJvr6g?si=22jiEN3LQy86Y8vD
// https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/

// BRUTE FORCE
/*
Time Complexity: O(N^2), we check the product of all possible subarrays using two nested loops.
Space Complexity: O(1), No extra space is used.
*/
int maxProduct(vector<int> &nums)
{
    // Initialize the answer with the first element
    int maxProd = nums[0];

    // Outer loop picks the starting index
    for (int i = 0; i < nums.size(); i++)
    {
        // Initialize current product to 1
        int prod = 1;

        // Inner loop picks the ending index
        for (int j = i; j < nums.size(); j++)
        {
            // Multiply current number to product
            prod *= nums[j];

            // Update maximum product if needed
            maxProd = max(maxProd, prod);
        }
    }

    // Return the result
    return maxProd;
}

// OPTIMAL 1
/*
Time Complexity: O(N), every element of array is visited once.
Space Complexity: O(1), constant number of variables are used.
*/
#include <bits/stdc++.h>
using namespace std;

// This function returns the maximum product subarray
// using prefix and suffix traversal
class Solution
{
public:
    int maxProductSubArray(vector<int> &arr)
    {
        // Store size of array
        int n = arr.size();

        // Initialize prefix and suffix product
        int pre = 1, suff = 1;

        // Initialize answer to negative infinity
        int ans = INT_MIN;

        // Traverse from both left and right
        for (int i = 0; i < n; i++)
        {
            // Reset prefix if zero
            if (pre == 0)
                pre = 1;

            // Reset suffix if zero
            if (suff == 0)
                suff = 1;

            // Multiply prefix with current element from front
            pre *= arr[i];

            // Multiply suffix with current element from back
            suff *= arr[n - i - 1];

            // Update the maximum of all products seen so far
            ans = max(ans, max(pre, suff));
        }

        // Return the final answer
        return ans;
    }
};

int main()
{
    // Sample input
    vector<int> arr = {2, 3, -2, 4};

    // Create object of solution
    Solution obj;

    // Call the function and print the result
    cout << obj.maxProductSubArray(arr) << endl;

    return 0;
}

// OPTIMAL 2
/*
Time Complexity: O(N), every element of array is visited once.
Space Complexity: O(1) , only constant variables are used.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // This function returns the maximum product
    // of any contiguous subarray using optimized approach
    int maxProduct(vector<int> &nums)
    {
        // Initialize answer, max and min product as first element
        int res = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        // Traverse from second element
        for (int i = 1; i < nums.size(); i++)
        {
            // Store current number
            int curr = nums[i];

            // If current number is negative, swap max and min
            if (curr < 0)
                swap(maxProd, minProd);

            // Update max and min product ending at current index
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            // Update global result
            res = max(res, maxProd);
        }

        // Return the result
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    Solution1 sol;
    cout << sol.maxProduct(nums);
    return 0;
}