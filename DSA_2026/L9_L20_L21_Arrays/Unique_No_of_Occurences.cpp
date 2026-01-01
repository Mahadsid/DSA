#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/*
In given array of integer, return true if the number of occurences of each value in the array is unique or return false.
*/

void countocc(int arr[], int n)
{
    unordered_map<int, int> freq; // count frequency of each element

    // Count occurrences
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Print frequency of each element
    for (auto &p : freq)
        cout << p.first << " occurs " << p.second << " times\n";

    // Check if all frequencies are unique
    unordered_set<int> seenFreq;
    for (auto &p : freq)
    {
        if (seenFreq.find(p.second) != seenFreq.end())
        {
            cout << "False\n"; // not unique
            return;
        }
        seenFreq.insert(p.second);
    }

    cout << "True\n"; // all unique
}

int main()
{
    int arr[6] = {1, 2, 2, 1, 1, 3};
    int crr[10] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    cout << "arr: ";
    countocc(arr, 6);

    cout << "\ncrr: ";
    countocc(crr, 10);

    return 0;
}

/*
🧩 Explanation:
- Step 1: Use hash map to count occurrences.
- Step 2: Use a hash set to ensure all frequencies are unique.

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)
✅ Output:
arr: False
crr: True
*/

// ANOTHER WAY

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    int crr[10] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    int n = 10;

    unordered_map<int, int> freq; // To store frequency of each element

    // Step 1: Count frequencies
    for (int i = 0; i < n; i++)
    {
        freq[crr[i]]++;
    }

    // Step 2: Use a set to track unique frequencies
    unordered_set<int> seenFreq;

    for (auto &p : freq)
    {
        int f = p.second;
        // If frequency already exists, not unique
        if (seenFreq.find(f) != seenFreq.end())
        {
            cout << "false";
            return 0;
        }
        seenFreq.insert(f);
    }

    cout << "true";
    return 0;
}

/*
🧩 Explanation:
- First loop → counts occurrences of each number.
- Second loop → checks if any frequency is repeated using a set.

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n) (for maps and sets)

✅ This is the most efficient and clean solution.
✅ Perfect for interviews.
*/

// ANOTHER WAY OF WRITING
#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;

    unordered_set<int> uniqueFreq;
    for (auto &p : freq)
        if (!uniqueFreq.insert(p.second).second)
            return false;

    return true;
}

int main()
{
    vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    cout << (uniqueOccurrences(arr) ? "true" : "false");
    return 0;
}

/*
🧩 Explanation:
- insert() returns {iterator, bool}. If bool == false → frequency already present.
- Compact, efficient, and very readable.

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)

✅ Best approach — clean, fast, and ideal for interviews.
*/

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ABOVE QUESTION FOR STRING
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// BRUTE FORCE
#include <iostream>
#include <string>
using namespace std;

bool uniqueCharOccurrences_Brute(string s)
{
    bool visited[256] = {false}; // ASCII range

    for (int i = 0; i < s.size(); i++)
    {
        if (visited[i])
            continue;

        // Count occurrences of s[i]
        int count = 1;
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                visited[j] = true;
                count++;
            }
        }

        // Compare with all other counts
        for (int k = 0; k < i; k++)
        {
            if (visited[k])
                continue;
            int otherCount = 0;
            for (int l = 0; l < s.size(); l++)
            {
                if (s[k] == s[l])
                    otherCount++;
            }
            if (otherCount == count && s[k] != s[i])
                return false;
        }
    }
    return true;
}

int main()
{
    string s = "aabbc";
    cout << (uniqueCharOccurrences_Brute(s) ? "true" : "false");
    return 0;
}

/*
🕒 Time Complexity: O(n³)
📦 Space Complexity: O(1)
⚠️ Works but very inefficient.
*/

// BEST APPROACH
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

bool uniqueCharOccurrences(string s)
{
    unordered_map<char, int> freq; // count frequency of each character

    // Step 1: Count character frequencies
    for (char ch : s)
        freq[ch]++;

    // Step 2: Check if frequencies are unique
    unordered_set<int> seenFreq;
    for (auto &p : freq)
    {
        if (seenFreq.find(p.second) != seenFreq.end())
            return false;
        seenFreq.insert(p.second);
    }

    return true;
}

int main()
{
    string s = "abcde"; // try "aabbc" also
    cout << (uniqueCharOccurrences(s) ? "true" : "false");
    return 0;
}

/*
🧩 Explanation:
- Count frequency of each character.
- Use a set to ensure each frequency value appears only once.

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)

✅ This is the recommended approach in interviews.
*/
