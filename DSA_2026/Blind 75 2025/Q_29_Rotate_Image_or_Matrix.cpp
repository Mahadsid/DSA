/*
48. Rotate Image
Medium
Topics
premium lock icon
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

STRIVER VID: https://youtu.be/Z0R2u6gd3GU?si=VBRS8OO1_LDghssh
STRIVER SOL: https://takeuforward.org/data-structure/rotate-image-by-90-degree

*/

//+++++++++++++++++++++++++++++++++++++++++ BRUTE FORCE+++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(N²),Each element of the matrix is visited exactly once and placed into a new matrix, so the time taken is proportional to the total number of elements.

Space Complexity: O(N²),We use an additional matrix of the same size to store the rotated result, leading to O(N²) extra space.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Function to rotate the matrix 90 degrees clockwise using extra space
    vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix)
    {
        // Get the size of the square matrix
        int n = matrix.size();

        // Create a new matrix of same size to store rotated result
        vector<vector<int>> rotated(n, vector<int>(n));

        // Traverse each element of original matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Place the element at its new rotated position
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        // Return the rotated matrix
        return rotated;
    }
};

// Driver code
int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution1 obj;
    vector<vector<int>> rotated = obj.rotateClockwise(mat);

    // Print the rotated matrix
    for (auto row : rotated)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

//++++++++++++++++++++++++++++++++++ OPTIMAL ++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(N²),We traverse every element once during transposition and again during reversal of each row, resulting in a total of O(N²) time.

Space Complexity: O(1),All operations are done in-place using only temporary variables. No extra matrix is used.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to rotate matrix 90 degrees clockwise in-place
    void rotateClockwise(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // Swap element at (i, j) with (j, i) to transpose
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i)
        {
            // Reverse the current row to complete clockwise rotation
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Driver code
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution obj;
    obj.rotateClockwise(matrix);

    // Print rotated matrix
    for (auto row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}