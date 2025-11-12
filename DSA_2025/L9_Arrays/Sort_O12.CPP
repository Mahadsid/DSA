// THIS QUESTION IS ALSO CALLED DUTCH NATIONAL FLAG QUESTION!
//+++++++++++++++++++++++++++++++++ SOLUTION  TRY BY ME ++++++++++++++++++++++++++++++
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOnetwo(int arr[], int n)
{

    int left = 0, mid = 0, right = n - 1;

    while (mid <= right)
    {
        // if element is 0
        if (arr[mid] == 0)
        {
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[right--]);
        }
    }
}

int main()
{

    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    int brr[3] = {2, 0, 1};
    int crr[2] = {1, 2};

    sortOnetwo(arr, 9);
    printArray(arr, 9);

    sortOnetwo(brr, 3);
    printArray(brr, 3);

    sortOnetwo(crr, 2);
    printArray(crr, 2);

    return 0;
}

//++++++++++++++++++++++++++++++++++ BRUTE FORCE +++++++++++++++++++++++++++++++

#include <bits/stdc++.h>
using namespace std;

void sort012_brute(int arr[], int n)
{
    sort(arr, arr + n); // Use inbuilt sort (O(n log n))
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    sort012_brute(arr, 9);
    printArray(arr, 9);
    return 0;
}

/*
🕒 Time Complexity: O(n log n)
📦 Space Complexity: O(1)
✅ Works but not optimal — in interviews, you’re expected to do it in O(n).
*/

//+++++++++++++++++++++++++++++++++++ OPTIMAL SOL- COUNTING METHOD +++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

void sort012_counting(int arr[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0; // counters

    // Count occurrences of 0, 1, and 2
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    // Rewrite the array with counted values
    int index = 0;
    while (count0--)
        arr[index++] = 0; // fill 0s
    while (count1--)
        arr[index++] = 1; // fill 1s
    while (count2--)
        arr[index++] = 2; // fill 2s
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    sort012_counting(arr, 9);
    printArray(arr, 9);
    return 0;
}

/*
🕒 Time Complexity: O(n)
📦 Space Complexity: O(1)
✅ Efficient and easy to understand.
⚠️ Not “in one pass”, but still acceptable in interviews.
*/

//++++++++++++++++++++++++++++++++ BEST APPROACH ONE PASS SOL +++++++++++++++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

// Function to sort 0s, 1s, and 2s using Dutch National Flag Algorithm
void sort012_optimal(int arr[], int n)
{
    int low = 0;      // points to next position of 0
    int mid = 0;      // current index being checked
    int high = n - 1; // points to next position of 2

    // Traverse until mid crosses high
    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]); // place 0 to left
            low++;                    // move low forward
            mid++;                    // move mid forward
        }

        else if (arr[mid] == 1)
        {
            mid++; // 1 is already in correct region
        }

        else
        {                              // arr[mid] == 2
            swap(arr[mid], arr[high]); // place 2 to right
            high--;                    // move high backward
            // Do NOT move mid here, as swapped value at mid needs to be checked
        }
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    int brr[3] = {2, 0, 1};
    int crr[2] = {1, 2};

    sort012_optimal(arr, 9);
    printArray(arr, 9); // ✅ Output: 0 0 0 1 1 1 1 2 2

    sort012_optimal(brr, 3);
    printArray(brr, 3); // ✅ Output: 0 1 2

    sort012_optimal(crr, 2);
    printArray(crr, 2); // ✅ Output: 1 2

    return 0;
}

/*
🧩 Explanation:
- low, mid, high divide array into 3 sections.
- Keep swapping to push 0s left, 2s right, 1s stay in middle.

🕒 Time Complexity: O(n)
📦 Space Complexity: O(1)
✅ Single-pass, in-place sorting → BEST APPROACH.
*/
