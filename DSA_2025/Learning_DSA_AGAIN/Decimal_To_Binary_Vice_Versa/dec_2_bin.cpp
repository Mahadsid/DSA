#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    /*
    taking in the decimal
    */
    int n;
    cin >> n;

    int i = 0;
    int ans = 0;

    while (n != 0) // while not zero continue
    {
        int bit = n & 1; // get the bit or binary

        if (bit == 1)
        { // if bit is = 1 then update ans
            ans = (bit * pow(10, i)) + ans;
        }

        n = n >> 1; // move the n, right shift
        i++;        // move the i also
    }
    cout << " Answer is " << ans << endl;
    return 0;
}
/*
See lec 6 LB for formula making
basically if 123 and you need make it same 123 the formula become
ans = (ans * 10) + digit
so at first ans = 0, and we get digit = 1
(0 x 10) + 1 -> 1
(1 x 10) + 2 -> 12
(12 x 10) + 3 -> 123
this way we get 123
if we need reverse just change formula
ans = (digit * power(10, i)) + ans
(1 * 10^0) + 0 -> 1
(2 * 10^1) + 1 -> 21
(3 * 10^2) + 0 -> 321
*/