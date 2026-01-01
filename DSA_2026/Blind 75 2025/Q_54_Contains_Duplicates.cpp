/*
217. Contains Duplicate
Easy
Topics
premium lock icon
Companies
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true



Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

// +++++++++++++++++++++++++++++++++++++++++++++++++ BRUTE FORCE++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(n²), because every pair of elements is compared using nested loops.

Space Complexity: O(1), no additional space is used beyond variables.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to check if array contains any duplicate elements
bool containsDuplicate(vector<int> nums)
{
    // Iterate through each element
    for (int i = 0; i < nums.size(); i++)
    {
        // Compare with every element ahead of it
        for (int j = i + 1; j < nums.size(); j++)
        {
            // If duplicate found, return true
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    // If no duplicates found, return false
    return false;
}

int main()
{
    // Sample input array
    vector<int> nums{1, 2, 3, 1};

    // Call function and store result
    bool res = containsDuplicate(nums);

    // Print result
    if (res)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++ BETTER ++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(n log n), due to the sorting step.

Space Complexity: O(1), assuming in-place sorting is used.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to check if duplicates exist using sorting
bool containsDuplicate(vector<int> nums)
{
    // Sort the array to bring duplicates together
    sort(nums.begin(), nums.end());

    // Compare adjacent elements after sorting
    for (int index = 1; index < nums.size(); index++)
    {
        if (nums[index] == nums[index - 1])
        {
            // Duplicate found
            return true;
        }
    }

    // No duplicates found
    return false;
}

int main()
{
    // Sample input array
    vector<int> nums{1, 2, 3, 1};

    // Call the function to check for duplicates
    bool res = containsDuplicate(nums);

    // Print the result
    cout << (res ? "true" : "false") << endl;

    return 0;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++ OPTIMAL++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(n), inserting n elements into a hash set takes average O(1) per insert.

Space Complexity: O(n), space used by the unordered set to store unique elements.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to check if duplicates exist using unordered_set
bool containsDuplicate(vector<int> nums)
{
    // Create a set to store unique elements
    unordered_set<int> set;

    // Insert all elements into the set
    for (int i = 0; i < nums.size(); i++)
    {
        set.insert(nums[i]);
    }

    // If duplicates exist, set size will be less than original array size
    return set.size() < nums.size();
}

int main()
{
    // Sample input
    vector<int> nums{1, 2, 3, 1};

    // Check for duplicates
    bool res = containsDuplicate(nums);

    // Print the result
    cout << (res ? "true" : "false") << endl;

    return 0;
}
