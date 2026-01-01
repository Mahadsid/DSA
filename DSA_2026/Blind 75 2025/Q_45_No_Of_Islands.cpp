/*
200. Number of Islands
Medium
Topics
premium lock icon
Companies
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

// CODEWITHMIK VID: https://youtu.be/yYKGNW6Y7BA?si=qOgfZ9JshPFMb3pd

//Code with mik SOL: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Number%20of%20Islands.cpp

*/

#include <bits/stdc++.h>
using namespace std;

/***************************************************** C++ ************************************************/
// Approach-1 (DFS)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution
{
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;

        /*
          You can also use lambda function for checking if next cell is valid or not
          auto isSafe = [&](int &i, int &j) {
            if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
                return false;
            return true;
          };
        */

        grid[i][j] = '$';

        for (pair<int, int> &p : dir)
        {
            int i_ = i + p.first;
            int j_ = j + p.second;
            dfs(grid, i_, j_);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

// Approach-2 (BFS)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution
{
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<char>> &grid, int i, int j, queue<pair<int, int>> &que)
    {
        que.push({i, j});
        grid[i][j] = '$';

        // lambda function (You can also add if check instead of lambda)
        auto isSafe = [&](int &i, int &j)
        {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
                return false;
            return true;
        };

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();

            for (auto &p : dir)
            {
                int i_ = curr.first + p.first;
                int j_ = curr.second + p.second;

                if (isSafe(i_, j_))
                {
                    que.push({i_, j_});
                    grid[i_][j_] = '$';
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j, que);
                    count++;
                }
            }
        }

        return count;
    }
};

// SIMILAR QUESTION: IN WHICH ALL DIRECTION ALLOWED, DIAGONALLY CONNECTED '1's are also connected and counted as one piece land. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
// STRIVER SOL: https://takeuforward.org/data-structure/number-of-islands
// Striver Vid: https://youtu.be/muncqlKJrH0?si=UHThg1Jd5oDi66ir
/*
Complexity Analysis.
Time Complexity: O(N*M), where N is the number of rows and M is the number of columns in the grid. Every cell is visited atleast once..
Space Complexity: O(N*M), additional space used for storing visited matrix and queue.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to perform BFS traversal
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        // Create a queue to store coordinates
        queue<pair<int, int>> q;
        // Push starting cell to queue
        q.push({row, col});
        // Mark the cell as visited
        vis[row][col] = 1;

        // Define all 8 directions
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        // Loop while queue is not empty
        while (!q.empty())
        {
            // Get front cell from queue
            int r = q.front().first;
            int c = q.front().second;
            // Pop it from the queue
            q.pop();

            // Traverse all 8 directions
            for (int i = 0; i < 8; i++)
            {
                // Calculate new row and column
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                // Check bounds and unvisited land
                if (nrow >= 0 && nrow < grid.size() &&
                    ncol >= 0 && ncol < grid[0].size() &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {

                    // Mark as visited and push to queue
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    // Function to count number of islands
    int numIslands(vector<vector<char>> &grid)
    {
        // Get grid dimensions
        int n = grid.size();
        int m = grid[0].size();

        // Create visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Counter for islands
        int count = 0;

        // Loop through entire grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If cell is unvisited land
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    // Increment island count
                    count++;
                    // Call BFS
                    bfs(i, j, vis, grid);
                }
            }
        }

        // Return total islands
        return count;
    }
};

// Driver code
int main()
{
    // Create grid
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    // Create Solution object
    Solution obj;
    // Call function and print result
    cout << obj.numIslands(grid) << endl;
    return 0;
}

// NOTE TO SELF:ANOTHER VERSION OF THIS IS NUMBER OF DISTINCT ISLANDS, DO IT ALSO!