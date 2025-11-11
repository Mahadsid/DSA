/*
LEETCODE 442
Given an integer array nums of legth n where all the integers of nums are in range [1,n] and eaach integer appear once or twice. return an array of all the integers that apper twice.
example 1: input nums = [4,3,2,7,8,2,3,1] output= [2,3]
example 2: input nums = [1,1] output=[1]
example 3: input nums = [1] output= []
*/

// +++++++++ BRUTE FORCE +++++++++

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    unordered_map<int, int> freq; // store count of each number
    vector<int> result;           // store numbers that appear twice

    // Count frequency of each number
    for (int num : nums)
        freq[num]++; // increment count for current number

    // Collect numbers whose frequency is 2
    for (auto &p : freq)
        if (p.second == 2)             // check if number appears twice
            result.push_back(p.first); // add to result

    return result; // return final list of duplicates
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums1 = {1, 1};
    vector<int> nums2 = {1};
    vector<int> ans = findDuplicates(nums2);

    for (int x : ans)
        cout << x << " "; // print output
    return 0;
}

/*
🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)
✅ Simple & clear, uses extra space.
*/

//++++++++++ BETTER APPROACH SORTING BASED++++++++

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // sort the array
    vector<int> result;             // store duplicates

    // Check adjacent elements for equality
    for (int i = 1; i < nums.size(); i++) // loop from 2nd element
        if (nums[i] == nums[i - 1])       // if same as previous
            result.push_back(nums[i]);    // it's a duplicate

    return result; // return duplicates
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums1 = {1, 1};
    vector<int> nums2 = {1};
    vector<int> ans = findDuplicates(nums2);

    for (int x : ans)
        cout << x << " ";
    return 0;
}

/*
🕒 Time Complexity: O(n log n)
📦 Space Complexity: O(1) extra (ignoring sort)
✅ Uses sorting instead of map.
*/

// +++++++++++ BEST APPROACH +++++++++++

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> result; // store duplicate numbers

    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1; // get index based on current number

        if (nums[index] < 0)                // if already negative, it's duplicate
            result.push_back(abs(nums[i])); // add duplicate to result
        else
            nums[index] = -nums[index]; // mark visited by negating
    }

    return result; // return all duplicates found
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums1 = {1, 1};
    vector<int> nums2 = {1};
    vector<int> ans = findDuplicates(nums2);

    for (int x : ans)
        cout << x << " "; // print output: 2 3
    return 0;
}

/*
🧩 Explanation:
- Each number refers to an index (num - 1).
- Negate that index to mark it's seen.
- If already negative → means we've seen it before → duplicate.

🕒 Time Complexity: O(n)
📦 Space Complexity: O(1) (modifies array in-place)
✅ Optimal approach — fast & memory efficient.
*/
