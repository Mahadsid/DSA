/*
79. Word Search
Medium
Topics
premium lock icon
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board?

//code with mik vid = https://youtu.be/whyax_vB8xY?si=7ToTaiqT_ozaQGs_

// code with mik sol = https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Word%20Search.cpp
*/
#include <bits/stdc++.h>
using namespace std;

/************************************************************ C++ ***************************************************/
/*Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)
Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from).
This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).
*/
class Solution
{
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>> &board, int i, int j, string &word, int idx)
    {
        if (idx >= l)
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (find(board, i_, j_, word, idx + 1))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if (m * n < l)
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && find(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
