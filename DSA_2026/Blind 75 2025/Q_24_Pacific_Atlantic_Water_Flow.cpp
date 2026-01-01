/*
417. Pacific Atlantic Water Flow
Medium

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.



Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.


Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

VIDEO: https://youtu.be/t0C4MzNf-1o?si=bCur5_SLm-mUIMZV

*/

#include <bits/stdc++.h>
using namespace std;

/*************************************************************** C++ ***************************************************************/
// Approach - 1
/*
    Do a DFS on every cell and if a cell reaches both (pacific and atlantic), mark them as the result
    TIme Complexity : (m*n)*(m*n)
*/

// Approach - 2 (Better DFS)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>> &heights, int i, int j, int prevCellVal, vector<vector<bool>> &visited)
    {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size())
        { // invalid cell
            return;
        }

        if (heights[i][j] < prevCellVal || visited[i][j])
            return;

        visited[i][j] = true;
        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();    // rows
        int n = heights[0].size(); // cols

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));  // pacificVisited[i][j] = true, means [i][j] water can go to Pacific //m*n
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false)); // atlanticVisited[i][j] = true, means [i][j] water can go to atlantic //m*n
        // T.C : O(m*n)
        // S.C : O(m*n)

        // Top Row and Bottom Row
        // Top Row : Pacific connected already
        // Bottom Row : atlantic connected already

        for (int j = 0; j < n; j++)
        {
            DFS(heights, 0, j, INT_MIN, pacificVisited);      // Top Row
            DFS(heights, m - 1, j, INT_MIN, atlanticVisited); // Top Row
        }

        // First col and last column
        // First col : Pacific connected already
        // Last col : atlantic connected already
        for (int i = 0; i < m; i++)
        {
            DFS(heights, i, 0, INT_MIN, pacificVisited);      // First column
            DFS(heights, i, n - 1, INT_MIN, atlanticVisited); // Last Column
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

// second solution : https://youtu.be/pDvvDvgHUKE?si=XpW-AuJh7SD-O8ZN
#include <vector>

#include <queue>

#include <unordered_set>

using namespace std;

class Solution
{

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        vector<vector<int>> result;

        if (heights.empty() || heights[0].empty())
            return result;

        int m = heights.size();

        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> pacQueue;

        queue<pair<int, int>> atlQueue;

        for (int i = 0; i < m; ++i)
        {

            pacQueue.push({i, 0});

            pacific[i][0] = true;

            atlQueue.push({i, n - 1});

            atlantic[i][n - 1] = true;
        }

        for (int j = 0; j < n; ++j)
        {

            pacQueue.push({0, j});

            pacific[0][j] = true;

            atlQueue.push({m - 1, j});

            atlantic[m - 1][j] = true;
        }

        bfs(pacQueue, pacific, heights);

        bfs(atlQueue, atlantic, heights);

        for (int i = 0; i < m; ++i)
        {

            for (int j = 0; j < n; ++j)
            {

                if (pacific[i][j] && atlantic[i][j])
                {

                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &ocean, vector<vector<int>> &heights)
    {

        int m = heights.size();

        int n = heights[0].size();

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty())
        {

            auto [r, c] = q.front();

            q.pop();

            for (auto &dir : directions)
            {

                int newRow = r + dir.first;

                int newCol = c + dir.second;

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n

                    && !ocean[newRow][newCol] && heights[newRow][newCol] >= heights[r][c])
                {

                    ocean[newRow][newCol] = true;

                    q.push({newRow, newCol});
                }
            }
        }
    }
};
