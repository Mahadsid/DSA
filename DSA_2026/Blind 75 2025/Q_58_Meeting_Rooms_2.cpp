/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example

Example 1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation: We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)

Example 2

Input: intervals = [(2,7)]
Output: 1
Explanation: Only need one meeting room
Approach :
Say you are an event organizer and you are organizing a tech event, which involves 4 different training sessions on a single day (e.g. one for Developers, one for DevOps folks, one for Security folks and one for DBAs) and out of these 4 sessions some of them will be held in parallel which means different training sessions running at the same time.

As an organizer you got the timings for each session : [2, 4] [1,7] [7, 8] [3, 5], e.g. 2 to 4 is Developers session, 1 to 7 is for DevOps folks and so on, now at minimum how many training rooms will you require to organize all the sessions? knowing that at anytime there can only be one training going on in one training room, but if a training room is free (means the next training session starts after the end of, one of the previous training session) then we can reuse the same training room.

We can solve this problem by first sorting all the training sessions according to their start time. So [2, 4] [1,7] [7, 8] [3, 5] becomes [1, 7] [2, 4] [3, 5] [7, 8] Next we iterate over the sorted training sessions, and we will check if the end time of the earliest ending training session is less than or equal to next training's start time, if thats the case, It means we can reuse the training room and don't need a new room.

We can use PriorityQueue to solve this problem, as we need to find the earliest ending training session. We add end time of a training session to the PriorityQueue. Note that we poll from the PriorityQueue, only when the head of the queue is less than or equal to the next training session's start time. This removes the older training session end time from the PriorityQueue.

Another important thing to note is, we always add the end time of the next training session to the PriorityQueue, regardless of whether we can reuse a room or need a new room. At the end we return the size of the PriorityQueue, because that reflects the minimum number of rooms that we will require.

🔥 Caution 🔥
From the implementation point of view, its important that we don't peek from the PriorityQueue if the PriorityQueue is empty. So isEmpty() check is necessary otherwise we will get NullPointerException when the PriorityQueue is empty.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
//heap, greedy, sort: time O(nlogn)
//a new interval will 1.add one new room; OR 2.add no new room.
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(Interval it : intervals){
            if(!min_heap.empty() && min_heap.top() <= it.start)
                min_heap.pop(); // will not overlap with this end time in the future, so pop it
            min_heap.push(it.end);
        }
        return min_heap.size();
    }

    bool static cmp(Interval i1, Interval i2){
        if(i1.start != i2.start)
            return i1.start < i2.start;
        else
            return i1.end < i2.end;
    }
};*/

#include <bits/stdc++.h>
using namespace std;

// use tree map
// direct solution: a begin time -> add one room, a end time -> delete one room
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int rlt = 0;
        map<int, int> map;
        for (Interval it : intervals)
        {
            map[it.start]++;
            map[it.end]--;
        }
        int tmpCount = 0;
        for (auto p : map)
        {
            tmpCount += p.second;
            rlt = max(rlt, tmpCount);
        }
        return rlt;
    }

    bool static cmp(Interval i1, Interval i2)
    {
        if (i1.start != i2.start)
            return i1.start < i2.start;
        else
            return i1.end < i2.end;
    }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        map<int, int> count;
        for (auto interval : intervals)
        {
            count[interval.start]++;
            count[interval.end]--;
        }
        int result = 0, tmp = 0;
        for (auto p : count)
        {
            tmp += p.second;
            result = max(result, tmp);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        vector<int> starts, ends;
        for (const auto &i : intervals)
        {
            starts.emplace_back(i.start);
            ends.emplace_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int min_rooms = 0, cnt_rooms = 0;
        int s = 0, e = 0;
        while (s < starts.size())
        {
            if (starts[s] < ends[e])
            {
                ++cnt_rooms; // Acquire a room.
                // Update the min number of rooms.
                min_rooms = max(min_rooms, cnt_rooms);
                ++s;
            }
            else
            {
                --cnt_rooms; // Release a room.
                ++e;
            }
        }
        return min_rooms;
    }
};