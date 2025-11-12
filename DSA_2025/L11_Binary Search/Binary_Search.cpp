#include <iostream>
using namespace std;

// CONDITION OF BS is elements in array should be in monotonic function!
// A monotonic function is a function that is either entirely non-increasing or entirely non-decreasing over its entire domain

// T.C = O(LOG N)

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;

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
        // always updtae mid at last, bcz mid depent on start or end and if they get updated so mind shhould be updated dont forget!
        mid = start + (end - start) / 2;
    }

    return -1;
}
int findPeak(int arr[], int n)
{

    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        // cout<<" s " << s <<" e " << e << endl;
        if (arr[mid] < arr[mid + 1])
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

int main()
{

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);

    cout << " Index of 6 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);

    cout << " Index of 14 is " << oddIndex << endl;

    int peakele = findPeak(even, 6);
    cout << " Index of peak element is " << peakele << endl;

    return 0;
}

int binarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;

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
int findPeak(int arr[], int n)
{

    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        // cout<<" s " << s <<" e " << e << endl;
        if (arr[mid] < arr[mid + 1])
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

int main()
{

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);

    cout << " Index of 6 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);

    cout << " Index of 14 is " << oddIndex << endl;

    int peakele = findPeak(even, 6);
    cout << " Index of peak element is " << peakele << endl;

    return 0;
}
