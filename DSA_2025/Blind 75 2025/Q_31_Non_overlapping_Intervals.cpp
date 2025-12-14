/*
435. Non-overlapping Intervals
Medium
Topics
premium lock icon
Companies
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
STRIVER VID: https://youtu.be/HDHQ8lAWakY?si=fPCM4TcQvojqRnud
STRIVER SOL: https://takeuforward.org/data-structure/overlapping-intervals
*/

/*
Complexity Analysis
Time Complexity: O(N*logN), we are sorting all the intervals and then traversing once.
Space Complexity: O(1), constant additional space is used.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the number of intervals to remove
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // Sort intervals based on end time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        // Initialize end to first interval's end
        int end = intervals[0][1];

        // Counter for non-overlapping intervals
        int count = 1;

        // Traverse all remaining intervals
        for (int i = 1; i < intervals.size(); i++)
        {
            // If current interval doesn't overlap
            if (intervals[i][0] >= end)
            {
                // Include this interval
                count++;
                // Update end time
                end = intervals[i][1];
            }
        }

        // Total to remove = total - non-overlapping
        return intervals.size() - count;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}