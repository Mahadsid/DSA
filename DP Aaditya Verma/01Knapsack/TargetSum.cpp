#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//same as count of Subset with give Diff

int CountSubSum(vector<int> arr,int n, int sum){
    if(n==0 || sum == 0){
        return 0;
    }
    // Base condition ko hi initialization m change hojati h n=0 so zero row m full(0); zero col/cap = full(0)
    vector<vector<int>> tab(n+1, vector<int>(sum+1));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0){
                tab[i][j] = 0;
            }
            if(j==0){
                tab[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < sum+1; j++)
        {   
            if(arr[i-1] <= j){
                tab[i][j] = (tab[i-1][j-arr[i-1]]) + ( tab[i-1][j] );
                //(no leliya to use minus krdo )||(no ni liya) jisse bhi subset true ayega use store krlenge
            }
            else if(arr[i-1] > j){
                tab[i][j] = tab[i-1][j]; 
            }      
        }
    }
    return tab[n][sum];
}

int CountNoOfSunsetWithGivenSum( vector<int> arr, int Diff){
    int sumarr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sumarr += arr[i]; 
    }
    
    int sum = Diff + sumarr / 2;
    int ans = CountSubSum(arr, arr.size(), sum);
    return ans; 
}

int main(){
    vector<int> arr = {1,1,2,3};
    int Diff = 1;
    cout << CountNoOfSunsetWithGivenSum(arr, Diff) << " = " << "NO" << endl;
}

// leetcode sol to handle edge cases
int findTargetSumWays(vector<int> nums, int S){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(S > sum || (sum-S)%2 != 0){
        return 0;
    }

    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(((sum-S)/2)+1));
    //int dp[n+1][((sum-S)/2)+1];

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] == 0){
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < ((sum-S)/2)+1; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < ((sum-S)/2)+1; j++)
        {   
            if(nums[i-1] <= j){
                dp[i][j] = (dp[i-1][j-nums[i-1]]) + ( dp[i-1][j] );
                //(no leliya to use minus krdo )||(no ni liya) jisse bhi subset true ayega use store krlenge
            }
            else if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j]; 
            }      
        }
    }
    return pow(2,c)*dp[nums.size()][((sum-S)/2)];
}

//anothe leetcode sol

class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {

        // Edge case when only one element is present in array
        if (a.size() == 1) {

            if (abs(a[0]) == abs(target))
                return 1;
            else
                return 0;
        }

        // We will solve problem considering there is no zeroes in the input array, and we will deal with it in the last

        // To count the number of zeroes
        int z = 0;

        for (int i = 0; i < a.size(); i++)
            if (a[i] == 0)
                z++;

        int asum = accumulate(a.begin(), a.end(), 0);

        // Because the sum of a subset can't be in decimals
        if ((asum + target) % 2 == 1)
            return 0;

        // This is the given sum, of which we have to find the number of count of subsets with sum equal to given sum
        int t = (asum + target) / 2;

        // Since we are dealing with only positive integers, so sum of a subset can't be negative
        if (t < 0)
            return 0;

        // DP Array
        //int dp[a.size() + 1][t + 1];
        vector<vector<int>> dp(a.size()+1, vector<int>(t+1));

        // Initialising DP Array
        for (int i = 0; i <= a.size(); i++) {
            for (int j = 0; j <= t; j++) {

                dp[i][j] = 0;

                if (i == 0)
                    dp[i][j] = 0;

                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= t; j++) {

                if (a[i - 1] == 0)
                    dp[i][j] = dp[i - 1][j];

                else if (a[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];

                else
                    dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];

            }
        }

        // Each zero can be put in either of the partitions, so 2^z ways to do this
        return pow(2, z) * dp[a.size()][t];

    }
};