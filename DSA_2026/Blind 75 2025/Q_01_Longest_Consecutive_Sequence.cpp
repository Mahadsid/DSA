/*
128. Longest Consecutive Sequence
Medium
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
// STRIVER SOL: https://youtu.be/oO5uLE7EUlM?si=HNAA9tuiS2DPplkq

//+++++++++++++++++++++ Better Sol with complexity of O(N) but using sort so extra o(n Log n)+++++++++++++++++++++++++++++++

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int longestConsecutiveSequence(vector<int> &nums)
{
    if (nums.size() == 0) // empty array -> 0
        return 0;
    sort(nums.begin(), nums.end()); // sort: O(n log n)
    int n = nums.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1; // at least one element exists
    for (int i = 0; i < n; i++)
    {
        if (nums[i] - 1 == lastSmaller)
        {
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (lastSmaller != nums[i])
        {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

/*
2) Better/Best (Recommended) — Hash set, linear average time

This is the standard O(n) average, O(n) space solution used in interviews.

Idea: Put all numbers in an unordered_set. For each number x that is a start of a sequence (i.e. x-1 not in set), walk forward x, x+1, x+2, ... counting length. This ensures each number is visited at most once overall.
*/
int longestConsecutiveSequenceBEST(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0) // empty array -> 0
        return 0;
    int longest = 1; // at least one element exists
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end()) // if we dont find previous number like for 2 we dont find 1 in set that means 2 can be a possible start of sequence and we see froward from 2 for sequence
        {
            int cnt = 1;
            int x = it;                        // x is the iterator for iterating in set
            while (st.find(x + 1) != st.end()) // while we dont find all sequence in set, example for 2 fe check 3 , 4, 5 and so on if we find those we inc count,
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt); // if after 2, 3, we dont got 4 so the condn will become st.find(x+1) == st.end() so we got out of while and update longest.
        }
    }
    return longest;
}

int main()
{
    vector<int> a1 = {100, 4, 200, 1, 3, 2};
    vector<int> a2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> a3 = {1, 0, 1, 2};
    cout << endl;
    cout << longestConsecutiveSequence(a1) << "\n"; // 4
    cout << longestConsecutiveSequence(a2) << "\n"; // 9
    cout << longestConsecutiveSequence(a3) << "\n"; // 3
    cout << endl;
    cout << "+++++++++++++++++++++++++++++++++";
    cout << endl;
    cout << longestConsecutiveSequenceBEST(a1) << "\n"; // 4
    cout << longestConsecutiveSequenceBEST(a2) << "\n"; // 9
    cout << longestConsecutiveSequenceBEST(a3) << "\n"; // 3

    return 0;
}