/*
39. Combination Sum
Medium
Topics
premium lock icon
Companies
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []


Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

STRIVER CODE : https://takeuforward.org/data-structure/combination-sum-1/
STRIVER : https://youtu.be/OyZFFqQtu98?si=8dNhX4kpn2pepi5b
*/

/*
Complexity Analysis

Time Complexity: O(2t * k) due to exploring all combinations up to the target with copying each valid combination of average length k.

Space Complexity: O(k * x) to store all valid combinations, where x is the number of combinations and k is their average length.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find all combinations of numbers that sum up to the target
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        // Base case: if we have considered all elements in the array
        if (ind == arr.size())
        {
            // If the target is zero, we have found a valid combination
            if (target == 0)
            {
                ans.push_back(ds); // Add the current combination to the result
            }
            return;
        }

        // Recursive case: pick the element if it's less than or equal to the target
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);                                // Add the current element to the combination
            findCombination(ind, target - arr[ind], arr, ans, ds); // Continue with the same index to allow repeated elements
            ds.pop_back();                                         // Backtrack by removing the last added element
        }

        // Skip the current element and move to the next index
        findCombination(ind + 1, target, arr, ans, ds);
    }

public:
    // Main function to get all combinations
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;                         // To store the result
        vector<int> ds;                                  // To store a current combination
        findCombination(0, target, candidates, ans, ds); // Start the recursive search
        return ans;                                      // Return all valid combinations
    }
};

int main()
{
    Solution obj;
    vector<int> v{2, 3, 6, 7}; // Candidate numbers
    int target = 7;            // Target sum

    // Get all combinations
    vector<vector<int>> ans = obj.combinationSum(v, target);

    // Output the combinations
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " "; // Print each element of the combination
        }
        cout << endl; // Print a newline after each combination
    }

    return 0;
}
