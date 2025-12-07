/*
1. Two Sum
Easy
Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

https://youtu.be/UXDSeD9mN-k?si=7KRTYLBE1gpEO5qf
*/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

//++++++++++++BRUTE FORCE+++++++++++++++
/*
for(i=0 to n){
    for(j=0 to n){
        if(i==j) continue; bcz cnnot pick same elements
        if(arr[i] == arr[j] == target){
            YES & save indexes.
        }
    }
}
o(N^2)
*/

// +++++++++++++++BETTER SOL++++++++++++++++++
/*
O(N) sol brain thought should be iterate only once or to go through elemnts only single time.
if we have first number say 8 and target = 14, then by maths other number shoud be 6, so to check if 6 exist or not in array HASHING(HASHMAP)would be a great and faster sol.
TC: O(N)IF MAP TAKES 0(1) BUT IF MAP TAKES 0(lon n) SO O(N * log N)
IF WE TAKE UNDORDERD MAP O(N), WORST CASE O(N^2)
SC: O(N)
*/

string read(int n, vector<int> arr, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int first_num = arr[i];
        int sec_num = target - first_num;
        if (mpp.find(sec_num) != mpp.end())
        {
            return "YES"; // for returning indexes return{mpp[sec_num], i};
        }
        mpp[first_num] = i;
    }
    return "NO";
}
// WITH INDEXEX CODE
vector<int> twoSumIndexes(vector<int> &nums, int target)
{
    map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int first_num = nums[i];
        int sec_num = target - first_num;
        if (mpp.find(sec_num) != mpp.end())
        {
            return {mpp[sec_num], i};
        }
        mpp[first_num] = i;
    }
    return {-1, -1};
}

// ANOTHER APPROACH OR IF INTERVIEWR SAY CANNOT USE MAP
/*
Then we can use 2 pointer approach (Greedy approach), this is for only yes or no else we have to use some other DS and store value with its indexes.
TC:0(N) WORST CASE O(N) + O(N LOG N)for sorting, SC=O(1) or O(N)we can say bcz we are changing the array
*/

string twoSumTwoPointer(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    sort(nums.begin(), nums.end());
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

int main()
{
    vector<int> a1 = {100, 4, 200, 1, 3, 2};
    vector<int> a2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> a3 = {1, 0, 1, 2};
    cout << "++++++++++++ WITH INDEXES ++++++++++++" << endl;
    vector<int> result = twoSumIndexes(a1, 201);
    for (int x : result)
    {
        cout << x << endl;
    }
    cout << endl;
    cout << "+++++++++++ WITH MAP ++++++++++++" << endl;
    cout << read(6, a1, 101) << "\n";
    cout << read(a2.size(), a2, 14) << "\n";
    cout << read(a3.size(), a3, 5) << "\n";
    cout << "++++++++++++ TWO POINTER +++++++++++++" << endl;
    cout << twoSumTwoPointer(a2, 14) << "\n";
    cout << twoSumTwoPointer(a3, 5) << "\n";

    return 0;
}