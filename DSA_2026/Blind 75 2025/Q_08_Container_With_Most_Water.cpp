/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

NeetCode : https://youtu.be/UuiTKBwPgAo?si=YdPjfn4zqemiF7Eb
*/

#include <bits/stdc++.h>
using namespace std;

//++++++++++++++++++++++++++++++++++ Brute Force: Take every elemnt in array and start form one ahead of it and calculate area, do this for every element TC:0(N2)+++++++++++++++++++++++++++++++++++++++++
int BruteForceWaterArea(vector<int> &height, int n)
{
    int res = 0;
    for (int l = 0; l < n; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            int area = (r - l) * min(height[l], height[r]);
            res = max(res, area);
        }
    }
    return res;
}

//++++++++++++++++++++++++++++++++++ Better Sol: 2 Pointer Approach TC:O(N)  ++++++++++++++++++++++++++++++++++++++++++

int WaterArea(vector<int> &height, int n)
{
    int res = 0;
    int l = 0;                 // left pointer at starting
    int r = height.size() - 1; // right pointer at extereme right

    while (l < r) // no need of = bcz, cannot calc area if poniting same element
    {
        int area = (r - l) * min(height[l], height[r]);
        res = max(res, area);
        if (height[l] < height[r]) // left height is small, so move left ponter forward to search big, bcz we need to maximize area.
        {
            l += 1;
        }
        else if (height[r] < height[l]) // right height is small, so move right ponter backward to search big, bcz we need to maximize area.
        {
            r -= 1;
        }
        else
        { // both equal so dosent matter can do l++, or can do r-- both are right,
            r -= 1;
        }
    }

    return res;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = height.size();
    cout << endl;
    cout << "Brute Force : " << BruteForceWaterArea(height, n) << endl;
    cout << "2 Pointer : " << WaterArea(height, n) << endl;

    return 0;
}