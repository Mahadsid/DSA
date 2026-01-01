// Leetcode 567
//  if any permutation of a part-string exsist in a string return true
// example s2= eidbaiii, s1= ab so
// permutation of ab = ab , ba
// since ba is present in s1 return true

#include <string>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool checkequal(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
            {
                return 0;
            }
        }
        return 1;
    }

public:
    bool checkInclusionString(string s1, string s2)
    {
        // char count array
        int count1[26] = {0};

        for (int i = 0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }
        // traverse s2 string in window of size s2 length and compare

        int i = 0;
        int windowsize = s1.length();
        int count2[26] = {0};
        while (i < windowsize)
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if (checkequal(count1, count2))
        {
            return 1;
        }
        while (i < s2.length())
        {
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;

            char oldchar = s2[i - windowsize];
            int index = oldchar - 'a';
            count2[index]--;

            i++;

            if (checkequal(count1, count2))
            {
                return 1;
            }
        }
        return 0;
    }
};

// +++++++++++++++++++++++++++++++++++++++ Above Solution — Corrected + Fully Explained(with comments) +++++++++++++++++++++++++++++++++++++++++++
/*
Explanation (Interview-Friendly)

A permutation of s1 exists in s2 if some substring of s2 has the same character frequency as s1.
So:
First count frequency of chars in s1.
Maintain a sliding window of length s1.size() in s2.
Every time the window moves:
Add right char
Remove left char
Compare frequency arrays
If at any window the frequency matches → permutation exists → return true.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if two freq arrays are equal
    bool checkEqual(int a[26], int b[26])
    {

        // compare frequency of each letter
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i]) // if any freq mismatch
                return false; // arrays not equal
        }
        return true; // all freq matched
    }

public:
    bool checkInclusionString(string s1, string s2)
    {

        // frequency array for s1
        int count1[26] = {0};

        // fill freq for characters of s1
        for (int i = 0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a'; // convert char to index 0-25
            count1[index]++;         // increase count
        }

        // sliding window of size = s1.length()
        int windowSize = s1.length();
        int count2[26] = {0}; // freq array for current window in s2

        // build initial window in s2
        int i = 0;
        while (i < windowSize && i < s2.length())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // check initial window
        if (checkEqual(count1, count2))
            return true;

        // sliding window starts
        while (i < s2.length())
        {

            // include new char into window
            int newIndex = s2[i] - 'a';
            count2[newIndex]++;

            // remove the char going out of window
            int oldIndex = s2[i - windowSize] - 'a';
            count2[oldIndex]--;

            // window moved forward, so increase i
            i++;

            // check if the new window matches frequency pattern
            if (checkEqual(count1, count2))
                return true;
        }

        return false; // no permutation found
    }
};
/*
| Step                        | Complexity   |
| --------------------------- | ------------ |
| Frequency creation          | O(26) = O(1) |
| Sliding window traversal    | O(n)         |
| Comparing arrays per window | O(26) = O(1) |
| **Total Time**              | **O(n)**     |
| **Space**                   | **O(1)**     |
*/

//++++++++++++++++++++++++++++++++++++++++ BEST APPROACH (Cleaner, Slightly Faster)**(Same logic, but shorter and cleaner—often preferred in interviews) Still O(n), O(1)+++++++++++++++++++++++++++++++++++++++++++

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        if (s1.size() > s2.size())
            return false;

        vector<int> freq(26, 0), window(26, 0);

        // build freq of s1
        for (char c : s1)
            freq[c - 'a']++;

        int k = s1.length();

        // create first window
        for (int i = 0; i < k; i++)
            window[s2[i] - 'a']++;

        if (window == freq)
            return true;

        // sliding window
        for (int i = k; i < s2.length(); i++)
        {

            window[s2[i] - 'a']++;     // include new character
            window[s2[i - k] - 'a']--; // remove old character

            if (window == freq)
                return true; // compare vectors
        }

        return false;
    }
};
