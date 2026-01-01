#include <bits/stdc++.h>
using namespace std;

int searchWithDuplicates(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // find middle index

        if (arr[mid] == target) // found target
            return mid;

        // ⚠️ Handle duplicates — when left, mid, and right are same
        if (arr[left] == arr[mid] && arr[mid] == arr[right])
        {
            left++; // shrink search space
            right--;
        }
        // ✅ Left half is sorted
        else if (arr[left] <= arr[mid])
        {
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1; // target lies in left sorted half
            else
                left = mid + 1; // target in right half
        }
        // ✅ Right half is sorted
        else
        {
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1; // target lies in right sorted half
            else
                right = mid - 1; // target in left half
        }
    }

    return -1; // not found
}

int main()
{
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};

    cout << searchWithDuplicates(arr, 0) << endl; // ✅ Output: 3
    cout << searchWithDuplicates(arr, 3) << endl; // ✅ Output: -1 (not found)

    return 0;
}

/*
🧩 Explanation:
- We handle duplicates by shrinking the search space when arr[left] == arr[mid] == arr[right].
- Otherwise, same logic as normal rotated binary search:
    → Identify sorted half
    → Check if target lies inside that half

🕒 Time Complexity: O(log n) average
⚠️ Worst Case: O(n)  (when duplicates cover large part of array)
📦 Space Complexity: O(1)
✅ Works for arrays with duplicates — Amazon/Google-level problem.
*/
