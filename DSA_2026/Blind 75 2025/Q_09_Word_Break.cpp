/*
139. Word Break
Medium
Topics
premium lock icon
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

Neetcode: https://youtu.be/Sx9NNgInc3A?si=sC_unqCtnzee5Rdi
https://youtu.be/hK6Git1o42c?si=2GcCNkkHvOvtFAvX

DP SOLUTION BETTER TO LOOK AT VIDEO!
*/

// GPT SOL
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Top-down memoization recursion
// Time: O(n * L) where L = maxWordLen (each start checks up to L substrings) -> O(n * L)
// Space: O(n) for memo + recursion depth
// Complexity note: Each index start is computed once; for each start we try at most maxWordLen substring checks. So time ≈ O(n * L) where L ≤ 20 (given constraints), effectively linear-ish.

bool dfs_memo(const string &s, const unordered_set<string> &dict,
              vector<int> &memo, int start, int maxWordLen)
{

    if (start == s.size())
        return true; // full segmentation success
    if (memo[start] != -1)
        return memo[start]; // return cached result

    // try substrings of length up to maxWordLen
    for (int len = 1; len <= maxWordLen && start + len <= s.size(); ++len)
    {
        if (dict.count(s.substr(start, len)))
        { // prefix is a word
            if (dfs_memo(s, dict, memo, start + len, maxWordLen))
                return memo[start] = 1; // cache and return true
        }
    }

    return memo[start] = 0; // no valid segmentation from start
}

bool wordBreak_memo(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end()); // O(1) lookups
    int n = s.size();
    int maxWordLen = 0;
    for (auto &w : wordDict)
        maxWordLen = max(maxWordLen, (int)w.size());

    vector<int> memo(n, -1); // -1 unknown, 0 false, 1 true
    return dfs_memo(s, dict, memo, 0, maxWordLen);
}

int main()
{
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    string s2 = "leetcode";
    vector<string> dict2 = {"leet", "code"};
    cout << boolalpha << wordBreak_memo(s, wordDict) << "\n"; // true
    cout << boolalpha << wordBreak_memo(s2, dict2) << "\n";
    return 0;
}

// ++++++++++++++++++++++++++++ GFG SOLUTION NOT CLEARLY DEFINED ++++++++++++
// #include <bits/stdc++.h>
// using namespace std;

// bool wordBreakRec(int ind, string &s, vector<string> &dictionary, vector<int> &dp)
// {
//     if (ind >= s.size())
//     {
//         return true;
//     }
//     if (dp[ind] != -1)
//         return dp[ind];
//     bool possible = false;
//     for (int i = 0; i < dictionary.size(); i++)
//     {
//         string temp = dictionary[i];
//         if (temp.size() > s.size() - ind)
//             continue;
//         bool ok = true;
//         int k = ind;
//         for (int j = 0; j < temp.size(); j++)
//         {
//             if (temp[j] != s[k])
//             {
//                 ok = false;
//                 break;
//             }
//             else
//                 k++;
//         }
//         if (ok)
//         {
//             possible |= wordBreakRec(ind + temp.size(), s, dictionary, dp);
//         }
//     }
//     return dp[ind] = possible;
// }

// bool wordBreak(string s, vector<string> &dictionary)
// {
//     int n = s.size();
//     vector<int> dp(n + 1, -1);
//     string temp = "";
//     return wordBreakRec(0, s, dictionary, dp);
// }
// int main()
// {
//     string s = "ilike";
//     vector<string> dictionary = {"i", "like", "gfg"};

//     cout << (wordBreak(s, dictionary) ? "true" : "false") << endl;
//     return 0;
// }
