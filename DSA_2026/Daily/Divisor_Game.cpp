/*
1025. Divisor Game
Solved
Easy
Topics
premium lock icon
Companies
Hint
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any integer x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Constraints:

1 <= n <= 1000
*/


class Solution {
public:

    bool solve(int n){
        // Alice will fail if odd at last
        if(n == 1) return false;
        if(n == 2) return true; // alice will win if sec-last chance it will get 2;
        
        for(int i = 1; i<=n; i++){ // checking for every possible x value
            if(n%i == 0){ // condition to be meet
                return !(solve(n-i)); // at every step n-x & changing bool val bcz
                // at first call we say alice is win so true, next for bob so we alter bool
            }
        }
        return false; //if not return true after checking all so bob win so we return false;
    }
    bool solveMemo(int n, vector<int> dp){
        if (n==0) return true;
        if (dp[n] != -1) return dp[n];
        
        for (int x = 1; x < n; x++){
            if (n%x==0){
                return dp[n] = !solveMemo(n-x, dp);
            }
        }
        return dp[n] =  false;
    } //if not return true after checking all so bob win so we return false;
    
    
    bool divisorGame(int n) {
        // vector<int> dp(n+1, -1);
        // return solveMemo(n, dp);
        //Solution 3 : Optimization-One Liner
        return !(n%2);
    }
};
