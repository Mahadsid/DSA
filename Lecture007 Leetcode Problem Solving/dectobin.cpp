#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int ans = 0;
    int i = 0;
    while (n != 0)
    {

        int bit = n & 1;

        ans = (bit * pow(10, i)) + ans;

        n = n >> 1;
        i++;
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