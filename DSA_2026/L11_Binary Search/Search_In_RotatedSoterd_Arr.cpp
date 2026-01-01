// Advamce question of Find Pivot in an array, just search part is more added.
// In that both lines are monotonic func  (A monotonic function is a function that is either entirely non-increasing or entirely non-decreasing over its entire domain)
// and tp implement search functionality on monotonic func we can use BS. just question is on which part or line we need to apply BS in this pivoted array,
// So if we find pivot element and compare target value i.e arr[pivot] <= Target <= arr[end] ie Target value lies between pivot and arr end so apply BS on 2nd line!!!!!
// else apply BS on 1st line but upto pivot-1 bcz pivot-1 represent the last index on 1st line!!!!!!!

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> &arr, int n)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {

        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(vector<int> &arr, int s, int e, int key)
{

    int start = s;
    int end = e;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right wala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        { // key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    { // BS on second line
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    { // BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main()
{

    vector<int> arr = {8, 10, 17, 1, 3};
    cout << findPosition(arr, 6, 10) << endl;
}

//  complexity O(logn)

// +++++++++++++++++++++++++++++++OTHER WAYS- BRUTE FORCE++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

int searchLinear(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target) // check each element
            return i;         // return index if found
    }
    return -1; // return -1 if not found
}

int main()
{
    vector<int> arr = {8, 10, 17, 1, 3};
    cout << searchLinear(arr, 10) << endl; // Output: 1
    return 0;
}

/*
🕒 Time Complexity: O(n)
📦 Space Complexity: O(1)
✅ Works always but not efficient — not acceptable in interviews.
*/

//+++++++++++++++++++++++++++++++++++++++++++++++ONE PASS MODIFIED BINARY SEARCH++++++++++++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

// Function to search in rotated sorted array in one pass
int searchOnePass(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // find mid safely

        if (arr[mid] == target)
            return mid; // found target, return index

        // Check which half is sorted
        if (arr[left] <= arr[mid])
        { // left half is sorted
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1; // target lies in left half
            else
                left = mid + 1; // target lies in right half
        }
        else
        { // right half is sorted
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1; // target lies in right half
            else
                right = mid - 1; // target lies in left half
        }
    }
    return -1; // target not found
}

int main()
{
    vector<int> arr = {8, 10, 17, 1, 3};
    cout << searchOnePass(arr, 10) << endl; // Output: 1
    return 0;
}

/*
🧩 Explanation:
- At each step, one half (left or right) is always sorted.
- We determine which half target lies in, and narrow our search.

🕒 Time Complexity: O(log n)
📦 Space Complexity: O(1)
✅ Fastest, cleanest, and most optimal method.
*/

// ++++++++++++++++++++++++++++++++++++++++++++++++ RECURSIVE BINARY SEARCH (VARIATION OF ONE PASS) ++++++++++++++++++++++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

int searchRecursive(vector<int> &arr, int left, int right, int target)
{
    if (left > right)
        return -1; // base case

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    // Left half sorted
    if (arr[left] <= arr[mid])
    {
        if (target >= arr[left] && target < arr[mid])
            return searchRecursive(arr, left, mid - 1, target);
        else
            return searchRecursive(arr, mid + 1, right, target);
    }
    // Right half sorted
    else
    {
        if (target > arr[mid] && target <= arr[right])
            return searchRecursive(arr, mid + 1, right, target);
        else
            return searchRecursive(arr, left, mid - 1, target);
    }
}

int main()
{
    vector<int> arr = {8, 10, 17, 1, 3};
    cout << searchRecursive(arr, 0, arr.size() - 1, 3) << endl; // Output: 4
    return 0;
}

/*
🕒 Time Complexity: O(log n)
📦 Space Complexity: O(log n) (due to recursion stack)
✅ Elegant, but iterative version preferred for low memory usage.
*/
