#include <bits/stdc++.h>
#include<iostream>
using namespace std;


bool isSafe(int row, int col, vector< vector<int>> &board, int n){
    //same row m, same col m, or same diagnol m na ho queen
    int x = row;
    int y = col;

    //check for same row
    while (y >= 0 )
    {
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    /* no need for checking col bcz we placing only one queen in one col and 
    making recursive call for next call and when backtracking we removing the queen 
    so no two queen can be placed on same col at same time
    */

   // check for diagonals

   x= row;
   y= col;

   while (x>=0 && y>=0)
   {
       if(board[x][y] == 1){
            return false;
        }
        y--;
        x--;
   }

   x= row;
   y= col;

   while (x<n && y>=0)
   {
       if(board[x][y] == 1){
            return false;
        }
        y--;
        x++;
   }

   return true;
// these checking costs 0(n) using map we get it in 0(1)
}

void addSolution( vector< vector<int>> &board, vector< vector<int>> &ans, int n){
    vector<int> temp;

    for(int i=0; i<n; i++){
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector< vector<int>> &ans, vector< vector<int>> &board, int n ){
    //base case sare col bhr gye honge
    if(col == n){
        addSolution(board, ans, n);
    }

    //solve 1 case rest recurssion will take care

    for (int row = 0; row < n; row++)
    {
        if(isSafe(row, col, board, n)){
            //place queen
            board[row][col] = 1;
            //recurssion
            solve(col+1, ans, board, n);
            //backtrack
            board[row][col] = 0;
        }
    }
    

}

vector<vector<int>> nQueens(int n)
{

    vector< vector<int>> board (n, vector<int> (n,0));
    vector< vector<int>> ans;
    
    solve(0, ans, board, n);

    return ans;

}
//tc=0(N!) sc=0(n*n)




// LEETCODE

    vector<vector<string> > sols; // 2D vector of strings to store the solutions
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return sols; 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
		    // No need to traverse more since the lower rows below current row attribute will always be safe.
			/* if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
			if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; */
	    }
	    return true;
    }
    // Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
    void solve(vector<string>& board, int row) {
	// Base condition. 
    // We reached the last row, so we have a solution so we add it to the solution vector
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	}            
	    // Try placing a queen on each column for a given row. 
        // Explore next row by placing Q at each valid column for the current row
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // Queen placed on a valid cell
			    solve(board, row + 1);    // Exploring next row
			    board[row][col] = '.';    // Backtracking to get all possible solutions
		    }
        }
    }