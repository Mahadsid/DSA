/*
347. Top K Frequent Elements
Medium
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]



Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.



Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn :  https://www.youtube.com/watch?v=GLw4WbJdYLw
    Company Tags                :  Amazon, Accolite
    Leetcode Qn Link            :  https://leetcode.com/problems/top-k-frequent-elements/
*/

// Approach-1 (Using min-heap) - TC : O(nlog(n-k))
class Solution
{
public:
    typedef pair<int, int> p;

    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // min-heap
        priority_queue<p, vector<p>, greater<p>> pq;

        // count frequency of each element
        //  Worst Case - n distinct elements are stored, so, space O(n)
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        // Push in min-heap and maintain size k
        for (auto it : mp)
        {
            pq.push({it.second, it.first});

            if (pq.size() > k)
                pq.pop();
        }

        // Pick all top K elements
        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// Approach-2 (Using Bucket Sort) - TC : O(n) - We visit all elements of nums only once.
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int &num : nums)
        {
            mp[num]++;
        }

        // index = frequency
        // Value will be elements
        // bucket[i] = elements occuring ith time
        vector<vector<int>> bucket(n + 1);

        for (auto &it : mp)
        {
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }

        // Pick from right to left to find max frequency elements
        vector<int> result;
        for (int i = n; i >= 0; i--)
        {

            if (bucket[i].size() == 0)
                continue;

            int size = bucket.size();
            while (bucket[i].size() > 0 && k > 0)
            {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return result;
    }
};