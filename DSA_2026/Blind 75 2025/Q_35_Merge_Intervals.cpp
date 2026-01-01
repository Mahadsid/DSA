/*
56. Merge Intervals
Medium
Topics
premium lock icon
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

//STRIVER SOL: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals
//STRIVER VID: https://youtu.be/IexN60k62jo?si=reWTbN-yGiBU_oWQ
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

//+++++++++++++++++++++++++++++++ BRUTE FORCE +++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N^2), for every interval we check all future intervals.
Space Complexity: ON), additonal space used to store the non-overlapping intervals.
*/
vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end());

    // Result array to store merged intervals
    vector<vector<int>> ans;

    // Loop through each interval
    int n = intervals.size();
    for (int i = 0; i < n;)
    {

        // Start of current merged interval
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Merge with all overlapping intervals
        int j = i + 1;
        while (j < n && intervals[j][0] <= end)
        {
            // Update end to the maximum of current end and overlapping interval's end
            end = max(end, intervals[j][1]);
            j++;
        }

        // Add the merged interval to result
        ans.push_back({start, end});

        // Move to the next non-overlapping interval
        i = j;
    }

    return ans;
}

//++++++++++++++++++++++++++++++++++++++++++++ OPTIMAL +++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N*logN) + O(N), we sort the entire array and then merge them in a single pass.
Space Complexity: ON), additonal space used to store the non-overlapping intervals.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        // Vector to store final merged intervals
        vector<vector<int>> merged;

        // Traverse each interval
        for (auto interval : intervals)
        {
            // If merged is empty or current interval does not overlap
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                // Add current interval as a new non-overlapping block
                merged.push_back(interval);
            }
            else
            {
                // Overlapping: merge by extending the end time
                merged.back()[1] = max(
                    merged.back()[1],
                    interval[1]);
            }
        }

        return merged;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = sol.merge(intervals);

    for (auto v : result)
    {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}

// ++++++++++++++++++++++ VIDEO SHOWN CODES +++++++++++++++++++++
//+++++++++++++ OPTIMAL VIDEO +++++++++++++++++
vector<vector<int>> mergeVIDEO(vector<vector<int>> &arr)
{
    // Sort intervals based on starting time
    sort(arr.begin(), arr.end());
    int n = arr.size();

    // Vector to store final merged intervals
    vector<vector<int>> ans;

    // Traverse each interval
    for (int i = 0; i < n; i++)
    {
        // If merged is empty or current interval does not overlap
        if (ans.empty() || arr[1][0] > ans.back()[1])
        {
            // Add current interval as a new non-overlapping block
            ans.push_back(arr[i]);
        }
        else
        {
            // Overlapping: merge by extending the end time
            ans.back()[1] = max(
                ans.back()[1],
                arr[i][1]);
        }
    }

    return ans;
}
//+++++++++++++++++++ BRUTE FORCE VIDEO++++++++++++++++++
vector<vector<int>> mergeBRUTEVIDEO(vector<vector<int>> &arr)
{

    // Sort intervals based on start time
    sort(arr.begin(), arr.end());

    // Result array to store merged intervals
    vector<vector<int>> ans;

    // Loop through each interval
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        // Start of current merged interval
        int start = arr[i][0];
        int end = arr[i][1];

        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // Merge with all overlapping intervals
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }

        // Add the merged interval to result
        ans.push_back({start, end});
    }

    return ans;
}