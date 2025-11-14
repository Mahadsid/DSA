#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // getting binary
    int n;
    cin >> n;

    int i = 0, ans = 0;

    while (n != 0)
    {
        // if i do % i get the right most digit ex 123 % 10 -> 3
        // so for bin ex 10101 % 10 -> 1
        int digit = n % 10;

        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }

        n = n / 10; // divide by 10 give me next in the digit ex 123 / 10 -> 12, so get access to "12" part of the number and in next iteration we work on it i.e 12 % 10 -> 2
        i++;
    }
    cout << ans << endl;
    return 0;
}
// example 21 bin will be 10101 so sol would be every 2 power place where 1 is present we keep it and ignore 0, so this we we get at first 1->2^0 so we keep it next is 0 at 2^1 we ignore it so at last we get 2^4 + 2^2 + 2^0 = 16 + 4 + 1 = 21 so we get same, just every binary bit keep the representation of 2^0 from right to left like for fist 2^0 then 2^1 then 2^3 then 2^4.