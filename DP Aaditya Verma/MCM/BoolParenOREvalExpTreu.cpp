#include <bits/stdc++.h>
#include<iostream>
using namespace std;

 vector<vector<pair<int,int>>> dp;
    pair<int,int> ways(string &s, int i, int j){
        if(i > j) return {0,0};
        if(i == j){
            if(s[i] == 'T') 
                return {1, 0};
            else 
                return {0, 1};
        }
        
        if(dp[i][j].first != -1) return dp[i][j];
        
        int trueCount=0;
        int falseCount=0;
        for(int k = i+1 ; k <= j ; k += 2){
            pair<int,int> leftCount = ways(s, i, k - 1); //left
            pair<int,int> rightCount = ways(s, k + 1, j); // right
            
            int lTrue = leftCount.first;
            int lFalse = leftCount.second;
            int rTrue = rightCount.first;
            int rFalse = rightCount.second;
            
            if(s[k] == '&'){
                trueCount += lTrue * rTrue;
                falseCount += (lFalse * rFalse + lFalse * rTrue + lTrue * rFalse);
            }else if(s[k] == '|'){
                trueCount += (lTrue * rFalse + lFalse * rTrue + lTrue * rTrue);
                falseCount += (lFalse * rFalse);
            }else{
                trueCount += (lFalse * rTrue + lTrue * rFalse);
                falseCount += (lFalse * rFalse + lTrue * rTrue);
            }
            trueCount %= 1003;
            falseCount %= 1003;
        }
        
        return dp[i][j] = {trueCount, falseCount};
    } 

    int countWays(int N, string S){
        dp.resize(N + 1, vector<pair<int,int>>(N + 1, {-1,-1}));
        return ways(S,0, N-1).first;
    }

