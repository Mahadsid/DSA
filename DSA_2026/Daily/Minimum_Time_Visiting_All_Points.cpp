/*
1266. Minimum Time Visiting All Points
Solved
Easy
Topics
premium lock icon
Companies
Hint
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
 

Example 1:


Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
*/

//++++++++++++++++++++++++++SOL+++++++++++++++++++++++++++++++
/*
Intuition
In a standard grid (Manhattan distance), moving diagonal is not allowed, so to go from (0,0) to (5,2) takes 5+2=7 steps. However, in this problem, diagonal movement is allowed and costs the same (1 second) as horizontal or vertical movement.

This means a diagonal move is a "superpower"—it lets you reduce both the horizontal and vertical distance to your target simultaneously.

If you need to move dx horizontally and dy vertically, you should use diagonal moves to reduce both until one of them becomes 0.
-Once one distance is 0, you simply walk in a straight line for the remaining distance.

Because the diagonal move covers both dimensions, the time taken is limited only by the longer of the two distances. This distance metric is known as the Chebyshev Distance.

Mathematical Proof
Let dx = |x2 - x1| and dy = |y2 - y1|. We want to reach the destination in minimum steps. The optimal strategy is to move diagonally as much as possible.
You can only move diagonally until one of the distances becomes 0. This means you can take min(dx,dy) diagonal steps.
This reduces both dx and dy by min(dx, dy).
Time taken so far: min(dx, dy).
After these moves, the smaller distance becomes 0. The remaining distance for the larger dimension is max(dx, dy) - min(dx, dy).
We cover this remaining distance with straight moves (horizontal or vertical).
Time taken for this part: max(dx, dy) - min(dx, dy).
image.png

Approach
Initialise ans to 0.
Iterate over the array from i = 1 to i = n - 1.
For each point x,y find the Chebyshev Distance between the current point (x2,y2) and previous point (x1,y1) and add it to ans.
Return ans.
Complexity
Time complexity: O(N) as whole array is traversed just once.
Space complexity: O(1) as only variables are stored.
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        for(int i = 0; i < points.size() - 1; i++){
            int currX = points[i][0];
            int currY = points[i][1];

            int targetX = points[i+1][0];
            int targetY = points[i+1][1];

            ans += max(abs(targetX - currX), abs(targetY - currY));
        }

        return ans;
    }
};
