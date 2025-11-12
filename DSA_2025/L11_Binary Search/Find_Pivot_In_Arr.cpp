#include <iostream>
using namespace std;

int getPivot(int arr[], int n)
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

int main()
{
    int arr[5] = {8, 10, 17, 1, 3};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}

/*

    |
    |    1st line
    |     /       e
    |    /       /
    |   /       /
    |   s      /2nd line
    |______________________

    [ 8 10  17  1  3]
    these numers are look like this in a map.

    cond1"
    arr[mid] >= arr[0], this cond shows we are on line 1 bcz if mid is greater than first element than all the gerater elemets lies on Ist line bcz all the elemnts of line 2nd are smaller than the arr[0] so mid should be lying on line 1st.
    so we update s, s = mid + 1;

    Cond 2:
    else case our mid lies on line 2nd so update end: e = mid;
     here we dont do e = mid - 1 as in Binary Search bcz doing -1 we can go on 1st line side of array and can miss pivot element.


*/