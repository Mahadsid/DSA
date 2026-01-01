// Card sorting

#include <vector>
using namespace std;

void insertionSort(int n, vector<int> &arr)
{

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {

            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            { // ruk jao
                break;
            }
        }
        // copy temp value
        arr[j + 1] = temp;
    }
}

// WHY insertion sort: adaptive algo!
// TC O(N^2), SC O(1)
//  BEST CASE: O(N)
//  WORST CASE: O(N^2)