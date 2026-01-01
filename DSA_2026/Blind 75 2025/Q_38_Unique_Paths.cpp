/*
62. Unique Paths
Medium
Topics
premium lock icon
Companies
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

// STRIVER SOL: https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8
//STRIVER VID: https://youtu.be/sdE0A2Oxofw?si=XJmcztursDY1FSBV
*/

// ++++++++++++++++++++++++++++++ MEMOISATION +++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), due to the storage of the DP array which keeps track of the number of unique paths to each cell in the grid.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to solve the problem using recursion
    int func(int i, int j, vector<vector<int>> &dp)
    {
        // Base case
        if (i == 0 && j == 0)
            return 1;

        /* If we go out of bounds or reach
        a blocked cell, there are no ways.*/
        if (i < 0 || j < 0)
            return 0;

        /* If we have already computed the number
        of ways for this cell, return it.*/
        if (dp[i][j] != -1)
            return dp[i][j];

        /* Calculate the number of ways by
        moving up and left recursively.*/
        int up = func(i - 1, j, dp);
        int left = func(i, j - 1, dp);

        // Store the result in dp table and return it.
        return dp[i][j] = up + left;
    }

public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n)
    {
        /* Initialize a memoization table (dp) to
        store the results of subproblems.*/
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Return the total count(0 based indexing)
        return func(m - 1, n - 1, dp);
    }
};
int main()
{
    int m = 3;
    int n = 2;

    // Create an instance of Solution class
    Solution sol;

    // Call the countWays function and print the result.
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    return 0;
}

// ++++++++++++++++++++++++++++++++++++++++ TABULATION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), as we are using a 2D array to store the results of subproblems. However, we can optimize this to O(n) by using a 1D array and updating it in place.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to solve the problem using tabulation
    int func(int m, int n, vector<vector<int>> &dp)
    {
        // Loop through the grid using two nested loops
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // Base condition
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    /* Skip the rest of the loop and
                    continue with the next iteration.*/
                    continue;
                }

                /* Initialize variables to store the number
                of ways from cell above (up) and left (left)*/
                int up = 0;
                int left = 0;

                /* If we are not at first row (i > 0), update
                'up' with the value from the cell above.*/
                if (i > 0)
                    up = dp[i - 1][j];

                /* If we are not at the first column (j > 0),
                update 'left' with value from the cell to left.*/
                if (j > 0)
                    left = dp[i][j - 1];

                /* Calculate the number of ways to reach the
                current cell by adding 'up' and 'left'.*/
                dp[i][j] = up + left;
            }
        }

        // The result is stored in bottom-right cell (m-1, n-1).
        return dp[m - 1][n - 1];
    }

public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n)
    {
        /* Initialize a memoization table (dp) to
        store the results of subproblems.*/
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Return the total count(0 based indexing)
        return func(m, n, dp);
    }
};
int main()
{
    int m = 3;
    int n = 2;

    // Create an instance of Solution class
    Solution sol;

    // Call the countWays function and print the result.
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++ SPACE OPTIMIZATION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are iterating through each cell in the grid once.

Space Complexity: O(n), as we are using two arrays of size n to store the current and previous rows. This is an optimization from the previous approaches that used a 2D array.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to solve the problem using space optimization.
    int func(int m, int n)
    {
        /* Initialize a vector to represent
        the previous row of the grid.*/
        vector<int> prev(n, 0);

        // Iterate through the rows of the grid.
        for (int i = 0; i < m; i++)
        {
            /* Create a temporary vector to
            represent the current row.*/
            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++)
            {
                // Base case
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                /* Initialize variables to store the number
                of ways from the cell above (up) and left (left).*/
                int up = 0;
                int left = 0;

                /* If we are not at the first row (i > 0), update
                'up' with the value from the previous row.*/
                if (i > 0)
                    up = prev[j];

                /* If we are not at the first column (j > 0),
                update 'left' with the value from current row.*/
                if (j > 0)
                    left = temp[j - 1];

                /* Calculate the number of ways to reach the
                current cell by adding 'up' and 'left'.*/
                temp[j] = up + left;
            }

            /* Update the previous row with values
            calculated for the current row.*/
            prev = temp;
        }

        /* The result is stored in the last
        cell of the previous row (n-1).*/
        return prev[n - 1];
    }

public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n)
    {

        // Return the total count(0 based indexing)
        return func(m, n);
    }
};
int main()
{
    int m = 3;
    int n = 2;

    // Create an instance of Solution class
    Solution sol;

    // Call the countWays function and print the result.
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    return 0;
}