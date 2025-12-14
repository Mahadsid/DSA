/*
49. Group Anagrams
Medium
Topics
premium lock icon
Companies
Given an array of strings strs, group the anagrams together. You can return the answer in any order.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]



Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
// neetcode: https://youtu.be/vzdNOK2oB2E?si=ZEz-yXimCcljmTSq
// codewith mik BRUTE FORCE : https://youtu.be/TNe3gF4r128?si=mZ2T1KalGxkBU8mo
*/
// C++ Code to group anagrams together by using frequency
// as keys

// Approach-2 CODEWITHMIK OPTIMAL SOLUTION: https://youtu.be/--k5-3EOObs?si=rb-joFtO3N00nUNm
// T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
// S.C : O(n*k)
class Solution
{
public:
    string generate(string &s)
    {
        int count[26] = {0};

        for (char &ch : s)
        {
            count[ch - 'a']++;
        }

        string new_s;

        for (int i = 0; i < 26; i++)
        {

            if (count[i] > 0)
            {
                new_s += string(count[i], i + 'a');
            }
        }

        return new_s;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string &s : strs)
        {
            string new_s = generate(s);

            mp[new_s].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &it : mp)
        {
            result.push_back(std::move(it.second));
        }

        return result;
    }
};

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// function to generate hash of word s
string getHash(string &s)
{
    string hash;
    vector<int> freq(MAX_CHAR, 0);

    // Count frequency of each character
    for (char ch : s)
        freq[ch - 'a'] += 1;

    // Append the frequency to construct the hash
    for (int i = 0; i < MAX_CHAR; i++)
    {
        hash.append(to_string(freq[i]));
        hash.append("$");
    }

    return hash;
}

vector<vector<string>> anagrams(vector<string> &arr)
{
    vector<vector<string>> res;
    unordered_map<string, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        string key = getHash(arr[i]);

        // If key is not present in the hash map, add
        // an empty group (vector) in the result and
        // store the index of the group in hash map
        if (mp.find(key) == mp.end())
        {
            mp[key] = res.size();
            res.push_back({});
        }

        // Insert the string in its correct group
        res[mp[key]].push_back(arr[i]);
    }
    return res;
}

int main()
{
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};

    vector<vector<string>> res = anagrams(arr);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}