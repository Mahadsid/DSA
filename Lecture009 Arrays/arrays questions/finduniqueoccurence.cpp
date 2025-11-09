#include <bits/stdc++.h>
#include <vector>
using namespace std;
using std::cout;
using std::endl;
using std::vector;

void countocc(int arr[], int n)
{
    // Mark all array elements as not visited
    vector<bool> visited(n, false);

    // Traverse through array elements and
    // count frequencies
    int z = 0, x = 0;
    int freq[100];
    for (int i = 0; i < n; i++)
    {

        for (int a = 0; a <= z; a++)
        {
            if (i == freq[a])
                i++;
        }

        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;
                freq[z] = i;
                z++;
                count++;
            }
        }
        x = x ^ count;

        cout << arr[i] << " " << count << endl;
    }
    if (x == 0)
        cout << "False\n";
    else
        cout << "True\n";
}
// return countarr;

int main()
{

    int arr[6] = {1, 2, 2, 1, 1, 3};
    int brr[2] = {1, 2};
    int crr[10] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    countocc(arr, 6);

    return 0;
}

// THIS CODE HAS A FLAW 😥😨
// int arr[6] = {1,2,2,1,1,3};
// BUT THIS EXAMPLE SHOULD RETURN TRUE, THE XOR FUNCTIONALITY GIVE WRONG ANS, XOR TO FUND UNIUENESS HAS A FLAW
//  x = 0
//  x = 0 ^ 3 = 3
//  x = 3 ^ 2 = 1
//  x = 1 ^ 1 = 0
/*
Why XOR doesn’t work here

XOR (^) is useful for problems like “find the element that appears once when all others appear twice”,
but it does not check for uniqueness of values.

That’s because:

XOR only tells whether the number of bits set in overlapping positions is even/odd.

It’s commutative and loses frequency information completely.

Two completely different sets of numbers can produce the same XOR result.

“I initially tried a bitwise XOR trick to detect uniqueness,
but I realized XOR only works for parity-based problems, not frequency uniqueness.
So I switched to using an unordered_map and unordered_set for accurate checking.”

correct ans check DSA 2025 ARRAYS.
*/