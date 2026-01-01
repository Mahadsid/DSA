/*
Given a character array s, reverse the order of the words. A word is defined as sequence of non space characters. The words in s will be seprated by single space. Your code must solve the problem in-place. example1: input s = [the sky is blue] output =[blue is sky the] example2: input s=[a] op=[a]
*/

// ++++++++++++++++++++++++++++++++++++++++++ C++ Optimal In-Place Solution+++++++++++++++++++++++++++++++++++++++++++

#include <bits/stdc++.h>
using namespace std;
// helper function: reverse characters from l to r
void reverseRange(vector<char> &s, int l, int r)
{
    while (l < r)
    {
        swap(s[l], s[r]); // swap characters
        l++;              // move left pointer
        r--;              // move right pointer
    }
}

vector<char> reverseWords(vector<char> &s)
{
    int n = s.size();

    // Step 1: reverse the whole array
    reverseRange(s, 0, n - 1);

    // Step 2: reverse each individual word
    int start = 0;
    for (int i = 0; i <= n; i++)
    {

        // when space or end is found, word boundary reached
        if (i == n || s[i] == ' ')
        {
            reverseRange(s, start, i - 1); // reverse current word
            start = i + 1;                 // move start to next word
        }
    }

    return s; // array modified in-place
}

int main()
{
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};

    reverseWords(s); // in-place reverse operation

    for (char c : s)
        cout << c; // prints: blue is sky the
}
