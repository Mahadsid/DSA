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