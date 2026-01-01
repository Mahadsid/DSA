/*
424. Longest Repeating Character Replacement
Medium
Topics
premium lock icon
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

STRIVER SOL : https://takeuforward.org/data-structure/longest-repeating-character-replacement
STRIVER VID: https://youtu.be/_eNhaDCr6P0?si=dUv99qqqhBDp74i1
*/

//++++++++++++++++++++++++++++ BRUTE FORCE ++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(n² × 26), where n is the length of the input string.This is because for every possible substring (which takes O(n²) time), we compute the frequency of each character (which takes O(26) = O(1) time since there are only 26 uppercase English letters). So total time complexity becomes O(n² × 26), which simplifies to O(n²).

Space Complexity: O(1), constant space.We use a fixed-size array of size 26 to store character frequencies for each substring. No additional space is used that grows with input size.
*/
// Function to find the length of the longest substring
// that can be made with the same letter after replacing at most k characters
#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{

    // Variable to store the maximum length of valid substring
    int maxLength = 0;

    // Traverse all possible substrings
    for (int i = 0; i < s.length(); i++)
    {

        // Initialize frequency array for current substring
        vector<int> freq(26, 0);

        // Track max frequency character in the current substring
        int maxFreq = 0;

        // Expand substring starting from index i
        for (int j = i; j < s.length(); j++)
        {

            // Update frequency of current character
            freq[s[j] - 'A']++;

            // Update the most frequent character seen so far
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            // Calculate total length of current substring
            int windowLength = j - i + 1;

            // Check how many characters we need to replace
            int replace = windowLength - maxFreq;

            // If number of replacements is within allowed k, update answer
            if (replace <= k)
            {
                maxLength = max(maxLength, windowLength);
            }
        }
    }

    return maxLength;
}

//++++++++++++++++++++++++++++ BETTER SOL +++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(N),We iterate through the entire string once using a sliding window. Each character is added and removed from the window at most once, resulting in linear time complexity relative to the length of the string (N).

Space Complexity: O(26) ,We use a fixed-size frequency array or hashmap to store counts of uppercase English letters (which are 26 in total), so the space used remains constant regardless of the input size.
*/
// Function to return the length of the longest substring that can be made of repeating characters
// by replacing at most k characters
int characterReplacement(string s, int k)
{

    // Map to count frequency of characters in current window
    unordered_map<char, int> freq;

    // Left pointer of the sliding window
    int left = 0;

    // Tracks the count of the most frequent character in the window
    int max_freq = 0;

    // Stores the result (maximum length found)
    int max_len = 0;

    // Traverse the string with right pointer
    for (int right = 0; right < s.length(); right++)
    {

        // Increase frequency of the current character
        freq[s[right]]++;

        // Update max frequency seen so far in the window
        max_freq = max(max_freq, freq[s[right]]);

        // If window is invalid (needs more than k replacements)
        while ((right - left + 1) - max_freq > k)
        {

            // Decrease frequency of the character at left
            freq[s[left]]--;

            // Shrink the window from the left
            left++;
        }

        // Update max_len with current valid window size
        max_len = max(max_len, right - left + 1);
    }

    // Return the final result
    return max_len;
}

//+++++++++++++++++++++++++++ OPTIMAL SOL +++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(n), where n is the length of the string,each character is processed at most twice once by the right pointer, once by the left. All operations inside the loop run in constant time.

Space Complexity: O(1), constant space .Only a fixed-size frequency array (26 letters) is used, regardless of input size.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the length of the longest substring that can be made of repeating characters
    // by replacing at most k characters
    int characterReplacement(string s, int k)
    {
        // Frequency array for A-Z
        vector<int> freq(26, 0);

        // Left and right pointers of sliding window
        int left = 0, right = 0;

        // Tracks the count of the most frequent character in current window
        int maxCount = 0;

        // Stores the maximum length of valid window
        int maxLength = 0;

        // Iterate through the string with right pointer
        while (right < s.size())
        {

            // Increment the frequency of current character
            freq[s[right] - 'A']++;

            // Update maxCount with the max frequency seen so far
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // If the current window needs more than k replacements, move left
            while ((right - left + 1) - maxCount > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update the maximum window length
            maxLength = max(maxLength, right - left + 1);

            // Move right pointer forward
            right++;
        }

        // Return the maximum valid window length
        return maxLength;
    }
};

// Driver code
int main()
{
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    // Output: 4
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}