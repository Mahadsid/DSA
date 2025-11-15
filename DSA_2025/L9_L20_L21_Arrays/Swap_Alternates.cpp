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

void swapAlternate(int arr[], int size)
{
    // i+=2 is important bcz we need to swap alternate, and to swap next pair in array we need to jump one index.
    for (int i = 0; i < size; i += 2)
    {
        // index should be inside the length of array
        if (i + 1 < size)
        {
            // swapping index and its alternative
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{

    int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
    int odd[5] = {11, 33, 9, 76, 43};

    swapAlternate(even, 8);
    printArray(even, 8);

    cout << endl;

    swapAlternate(odd, 5);
    printArray(odd, 5);

    return 0;
}

// swapping two elements without using swap function : we need to use another var
/*
ex swap [5, 2]
temp = arr[1]
arr[1] = arr[0]
arr[0] = temp
swapped = [2, 5]
*/