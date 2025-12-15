/*
57. Insert Interval
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

//STRIVER VID: https://youtu.be/xxRE-46OCC8?si=KOXRGKFWQ8dSxF0R
//STRIVER SOL: https://takeuforward.org/data-structure/insert-new-interval
*/

/*
Complexity Analysis
Time Complexity: O(n), where n is the number of intervals. We traverse through the list of intervals once to insert and merge the new interval.

Space Complexity: O(n), where n is the number of intervals. We store the result in a new list which can potentially contain all intervals.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // To insert new interval
    vector<vector<int>> insertNewInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        // Initialize a vector
        vector<vector<int>> res;

        /* Track the index while
        iterating through
        intervals */
        int i = 0;

        // Get total intervals
        int n = intervals.size();

        // Insert intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            /* Add intervals to the result vector
            until their end time is before
            the start time of newInterval */

            res.push_back(intervals[i]);
            // Move to next interval
            i = i + 1;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            /* Update the start time of newInterval to the
            minimum of its current start time and the
            start time of the current interval */
            newInterval[0] = min(newInterval[0], intervals[i][0]);

            /* Update the end time of newInterval to the
            maximum of its current end time and the
            end time of the current interval */
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            // Move to the next interval
            i = i + 1;
        }

        /* Insert the merged interval
        Add the merged interval to
        the result vector */
        res.push_back(newInterval);

        /* Insert remaining
        intervals after
        newInterval */
        while (i < n)
        {

            /* Add the remaining intervals
            after newInterval to the result
            vector */
            res.push_back(intervals[i]);

            // Move to next interval
            i = i + 1;
        }

        // Return result vector
        return res;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 4}, {6, 7}, {8, 10}, {12, 16}};
    cout << "Intervals Array: ";
    for (auto interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    }
    cout << endl;

    vector<int> newInterval = {5, 8};
    cout << "New Interval to be Inserted: ";
    cout << "[" << newInterval[0] << ", " << newInterval[1] << "]" << endl;

    Solution sol;
    vector<vector<int>> result = sol.insertNewInterval(intervals, newInterval);
    for (auto interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    }
    cout << endl;

    return 0;
}