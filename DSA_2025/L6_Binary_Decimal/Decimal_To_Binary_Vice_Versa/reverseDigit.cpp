#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {

        int ans = 0;
        while (x != 0)
        {

            int digit = x % 10;

            // if outside int range return;
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
            {
                return 0;
            }

            ans = (ans * 10) + digit;
            x = x / 10;
        }
        return ans;
    }
};

/*
another simple formula
ans = (ans * 10) + digit;
123 -?
(0 x 10 ) + 3 -> 3
(3 x 10 ) + 2 -> 32
(32 x 10 ) + 1 -> 321
*/

/*
if we need reverse just change formula
ans = (digit * power(10, i)) + ans
(1 * 10^0) + 0 -> 1
(2 * 10^1) + 1 -> 21
(3 * 10^2) + 21 -> 321
*/
