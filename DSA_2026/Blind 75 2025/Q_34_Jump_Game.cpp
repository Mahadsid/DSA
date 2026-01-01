/*
55. Jump Game
Medium
Topics
premium lock icon
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

// STRIVER VID: https://youtu.be/tZAa_jJ3SwQ?si=OJskF5rvO_Mw1ZKn
// STRIVER SOL: https://takeuforward.org/Greedy/jump-game-i
*/

/*
Complexity Analysis

Time Complexity: O(N) where N is the length of the input array. We iterate through the input array exactly once and at each element perform constant time operations.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Class to solve the Jump Game problem
class JumpGame
{
public:
    // Function to determine if you can reach the last index
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0; // The farthest index we can currently reach

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            // If current index is beyond the farthest reachable point
            if (i > maxIndex)
            {
                return false; // We cannot move further
            }

            // Update the farthest index we can reach
            maxIndex = max(maxIndex, i + nums[i]);
        }

        // If we finish the loop, we can reach the last index
        return true;
    }
};

int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    JumpGame game;
    bool ans = game.canJump(nums);

    if (ans)
        cout << "It is possible to reach the last index." << endl;
    else
        cout << "It is not possible to reach the last index." << endl;

    return 0;
}