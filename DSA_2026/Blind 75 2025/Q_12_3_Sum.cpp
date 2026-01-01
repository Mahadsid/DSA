/**
 * 15. 3Sum
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105


*/
// STRIVER: https://youtu.be/DhFh8Kw7ymk?si=fjphg3ZkdOTCqASu

// ++++++++++++ BRUTE FORCE : Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
// Reason : Here, we are mainly using 3 nested loops.And inserting triplets into the set takes O(log(no.of unique triplets)) time complexity.But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

// Space Complexity : O(2 * no.of the unique triplets) as we are using a set data structure and a list to store the triplets.++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++
#include <bits/stdc++.h>
using namespace std;

// Class to solve 3-sum problem
class Solution
{
public:
    // Function to find triplets with sum zero
    vector<vector<int>> threeSum(vector<int> &arr, int n)
    {
        // Store unique triplets
        set<vector<int>> st;

        // First loop for first element
        for (int i = 0; i < n; i++)
        {
            // Second loop for second element
            for (int j = i + 1; j < n; j++)
            {
                // Third loop for third element
                for (int k = j + 1; k < n; k++)
                {
                    // If triplet sum is zero
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        // Store sorted triplet to avoid duplicates
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp); // store in set to avoid duplicates bcz we need to give unquie in output.
                    }
                }
            }
        }

        // Convert set to vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// Driver code
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    Solution obj;
    vector<vector<int>> res = obj.threeSum(arr, n);

    for (auto &triplet : res)
    {
        for (auto &num : triplet)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}

// ++++++++++++++++++++++++++ BETTER SOL++++++++++++++++++++
// Time Complexity: O(N2 * log(no. of unique triplets)),as we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

// Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.

#include <bits/stdc++.h>
using namespace std;

// Class to solve 3-sum problem
class Solution
{
public:
    // Function to find triplets with sum zero
    vector<vector<int>> threeSum(vector<int> &arr, int n)
    {
        // Store unique triplets
        set<vector<int>> ans;

        // First loop for first element
        for (int i = 0; i < n; i++)
        {
            // New/Fresh Set to store elements seen in this iteration
            set<int> hashset;

            // Second loop for second element
            for (int j = i + 1; j < n; j++)
            {
                // Calculate third element needed
                int third = -(arr[i] + arr[j]);

                // If third already in set, we found a triplet
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }

                // Add current element to set
                hashset.insert(arr[j]);
            }
        }

        // Convert set to vector
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

// Driver code
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    Solution obj;
    vector<vector<int>> res = obj.threeSum(arr, n);

    for (auto &triplet : res)
    {
        for (auto &num : triplet)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}

//+++++++++++++++++++++++ OPTIMAL Approach Complexity Analysis

// Time Complexity: O(NlogN)+O(N2), as The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2).

// Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1). written as O(1).+++++++++++++++++++++++++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

// Class to solve 3-sum problem
class Solution
{
public:
    // Function to find triplets with sum zero
    vector<vector<int>> threeSum(vector<int> &arr, int n)
    {
        // Sort the array
        sort(arr.begin(), arr.end());
        // Store final result
        vector<vector<int>> ans;

        // First loop for first element
        for (int i = 0; i < n; i++)
        {
            // Skip duplicates for first element
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            // Two pointers
            int left = i + 1, right = n - 1;

            // Find pairs for current arr[i]
            while (left < right)
            {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0)
                {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    left++, right--;

                    // Skip duplicates for left
                    while (left < right && arr[left] == arr[left - 1])
                        left++;
                    // Skip duplicates for right
                    while (left < right && arr[right] == arr[right + 1])
                        right--;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return ans;
    }
};

// Driver code
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    Solution obj;
    vector<vector<int>> res = obj.threeSum(arr, n);

    for (auto &triplet : res)
    {
        for (auto &num : triplet)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}