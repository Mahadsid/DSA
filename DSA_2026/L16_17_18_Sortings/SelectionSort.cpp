// Find the smallest and fix it in its right place.

#include <vector>
using namespace std;
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++) // n-1 Bcz last element is already sorted no need to consider it.
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

// T.C O(N^2), S.C O(1)
// BEST CASE: O(N^2)
// WORST CASE: O(N^2)
// USE CASE: WHEN ARRAY SIZE IS SMALL WE CAN USE SELECTION SORT.

/*
 5 3 6 9
round 1 : 3 5 6 9
round 2 : 3 5 6 9
round 3 : 3 5 6 9
*/