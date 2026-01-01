#include <vector>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        // for round 1 to n-1
        bool swapped = false;

        for (int j = 0; j < n - i; j++)
        {

            // process element till n-i th index
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            // already sorted
            break;
        }
    }
}

// at every iteration we compare arr[j] > arr[j + 1] element and its next position element if they are not in sorted order we swap them and make them in sorted oreder.
// we do this for rounds, what it do -> at every round the largest element gets placed in its righr position.

// TC O(N^2), SC O(1)
// BEST CASE O(N)
// WORST CASE O(N^2)