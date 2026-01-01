/*
207. Course Schedule
Medium
Topics
premium lock icon
Companies
Hint
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

//STRIVER VID: https://youtu.be/WAOfKpxYHR8?si=7hluN5yDDTMsH-2U
//STRIVER SOL: https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24
*/

#include <bits/stdc++.h>
using namespace std;

// +++++++++++++++++ Course Schedule 1 +++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(V+E), each course and pre-requisite edge is processed once.
Space Complexity: O(V+E), additional space is used for storing adjacency list and queue.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Function to verify if all courses can be finished
    bool canFinish1(int numCourses,
                    vector<vector<int>> &prerequisites)
    {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        // Build in-degree array
        vector<int> inDegree(numCourses, 0);

        // Fill adjacency and in-degree
        for (auto &pre : prerequisites)
        {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        // Initialize queue with zero in-degree nodes
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Count processed nodes
        int count = 0;

        // Process queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            // Reduce in-degree of neighbors
            for (int nei : adj[node])
            {
                inDegree[nei]--;
                if (inDegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        // Return true if all nodes processed
        return count == numCourses;
    }
};

int main()
{
    Solution1 sol;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    cout << (sol.canFinish1(numCourses, prerequisites)
                 ? "true"
                 : "false");
    return 0;
}

//+++++++++++++++++++++++++++++++++++ course schedule 2 ++++++++++++++++++++++++++++++++++++++++++++++++++

/*
Algorithm
Here the setup is the same, but instead of just checking feasibility, we want the actual order of course completion. This order must respect the prerequisite rules, which is exactly what a topological sort does on a DAG. If a cycle exists, no valid order exists and we return an empty list. If no cycle exists, we can either perform a DFS-based topological sort or use BFS with in-degrees (Kahn’s algorithm) to construct a valid sequence. The key intuition is that finding the course order is equivalent to generating a topological ordering of the directed graph.
Build an adjacency list where each prerequisite pair [a, b] creates a directed edge from b to a.
Create an array to store the number of prerequisites for each course and fill it while building the graph.
Put all courses with zero prerequisites into a queue.
While the queue is not empty, remove a course, add it to the order, and decrease the prerequisite count of its neighbors.
If a neighbor’s count becomes zero, add it to the queue.
At the end, if the order contains all courses return it, otherwise return an empty list.
*/
/*
Complexity Analysis
Time Complexity: O(V+E), each course and pre-requisite edge is processed once.
Space Complexity: O(V+E), additional space is used for storing adjacency list, queue and ordering array.
*/
class Solution
{
public:
    // Function to find ordering of courses
    vector<int> findOrder(int numCourses,
                          vector<vector<int>> &prerequisites)
    {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        // Build in-degree array
        vector<int> inDegree(numCourses, 0);

        // Fill adjacency and in-degree
        for (auto &pre : prerequisites)
        {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        // Initialize queue with zero in-degree nodes
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Create result list
        vector<int> order;

        // Process queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);

            // Reduce in-degree of neighbors
            for (int nei : adj[node])
            {
                inDegree[nei]--;
                if (inDegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        // Return order if valid, else empty
        if ((int)order.size() == numCourses)
        {
            return order;
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;
    vector<int> ans = sol.findOrder(numCourses, prerequisites);
    for (int x : ans)
        cout << x << " ";
    return 0;
}