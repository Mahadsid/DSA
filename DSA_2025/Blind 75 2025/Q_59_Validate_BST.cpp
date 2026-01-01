/*
98. Validate Binary Search Tree
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

/*
Complexity Analysis
Time Complexity: O(N) , for traversing N nodes.

Space Complexity: O(1) , if we ignore the auxiliary stack space.
*/

// Function to perform binary search to check if an element is present in the array
bool bSearch(int elem, int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    // Perform binary search
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // If element is found, return true
        if (arr[mid] == elem)
            return true;

        // If the element is greater than mid, search in the right half
        else if (arr[mid] < elem)
            start = mid + 1;

        // If the element is smaller than mid, search in the left half
        else
            end = mid - 1;
    }
    return false; // If the element is not found
}

// Function to check if arr1[] is a subset of arr2[]
bool isSubset(int arr1[], int m, int arr2[], int n)
{

    // Sort arr2[] for efficient binary search
    sort(arr2, arr2 + n);

    // If arr1[] has more elements than arr2[], it cannot be a subset
    if (m > n)
        return false;

    // For each element in arr1[], check if it exists in arr2[]
    for (int i = 0; i < m; i++)
    {
        bool present = bSearch(arr1[i], arr2, n); // Check if arr1[i] is present in arr2[]

        // If any element from arr1[] is not present in arr2[], return false
        if (present == false)
            return false;
    }

    // If all elements of arr1[] are found in arr2[], return true
    return true;
}

// Driver function
int main()
{
    // Initialize arrays
    int arr1[] = {1, 3, 4, 5, 2};
    int arr2[] = {2, 4, 3, 1, 7, 5, 15};

    // Calculate the sizes of the arrays
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Call the isSubset function
    bool ans = isSubset(arr1, m, arr2, n);

    // Output the result
    if (ans == true)
        cout << "arr1[] is a subset of arr2[]";
    else
        cout << "arr1[] is not a subset of arr2[]";

    return 0;
}
