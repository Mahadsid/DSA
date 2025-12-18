/*
73. Set Matrix Zeroes
Medium
Topics
premium lock icon
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

//Striver Sol:https://takeuforward.org/data-structure/set-matrix-zero
//striver Vid: https://youtu.be/N0MgLvceX7M?si=WtGxWxZl_bS751vh
*/

//+++++++++++++++++++++++++++++++++++++++ BRUTE FORCE ++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(m * n * (m + n)), We iterate through every cell (m * n), and for each zero, we potentially mark its entire row (O(n)) and column (O(m)), leading to O(m * n * (m + n)) overall.

Space Complexity: O(1), We are not using any extra data structures, only modifying the matrix in place (apart from a few variables).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Get number of rows
        int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();

        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If current cell is zero
                if (matrix[i][j] == 0)
                {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++)
                    {
                        if (matrix[i][col] != 0)
                            matrix[i][col] = -1;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++)
                    {
                        if (matrix[row][j] != 0)
                            matrix[row][j] = -1;
                    }
                }
            }
        }

        // Second pass: replace all -1 markers with 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    // Example matrix
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Create Solution object
    Solution sol;
    // Call function to modify matrix
    sol.setZeroes(matrix);

    // Print final matrix
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ BETTER+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(m × n),We make two passes over the matrix.First pass to identify rows and columns to be zeroed (O(m × n)).Second pass to update the matrix using the markers (O(m × n)).Total time is proportional to the number of cells in the matrix, so O(m × n).
Space Complexity: O(m + n),We store two extra arrays one for m rows and one for n columns. No other extra space is used besides these arrays.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Get number of rows
        int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();

        // Create row marker array
        vector<int> row(m, 0);
        // Create column marker array
        vector<int> col(n, 0);

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If element is zero, mark its row and column
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set cells to zero based on markers
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the row or column is marked, set cell to zero
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    // Create the matrix
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Create Solution object
    Solution obj;
    // Call function
    obj.setZeroes(matrix);

    // Print the updated matrix
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ OPTIMAL +++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(m × n),We iterate over the entire matrix a constant number of times (first pass for markers, second pass for zeroing, final pass for first row/col), where m = number of rows and n = number of columns.

Space Complexity: O(1),No extra space is used apart from a few boolean flags; all marker information is stored within the first row and column of the matrix itself.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0 (Optimal O(1) space)
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Get dimensions of matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Flag to track if first row should be zeroed
        bool firstRowZero = false;
        // Flag to track if first column should be zeroed
        bool firstColZero = false;

        // Check if first row has any zero
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns in first row/column
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero based on markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (firstRowZero)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if (firstColZero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    obj.setZeroes(matrix);
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}