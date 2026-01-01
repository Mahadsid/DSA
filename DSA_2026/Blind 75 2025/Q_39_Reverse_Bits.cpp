/*
190. Reverse Bits
Easy
Topics
premium lock icon
Companies
Reverse bits of a given 32 bits signed integer.



Example 1:

Input: n = 43261596

Output: 964176192

Explanation:

Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000
Example 2:

Input: n = 2147483644

Output: 1073741822

Explanation:

Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110


Constraints:

0 <= n <= 231 - 2
n is even.


Follow up: If this function is called many times, how would you optimize it?

// NEETCODE VID: https://youtu.be/UcoN6UjAI64?si=itnla_ihUlbBBmWr
*/

// CODE WITH ALISHA: https://youtu.be/FMdQxjiqg2I?si=yDCy_oEDlu8J7_h3
#include <bits/stdc++.h>
using namespace std;

bool findIfKthBitSet(int pos, int org_num)
{
    if (((1 << (pos - 1)) & org_num) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int reverseBits(int n)
{
    int ans = 0;
    for (int i = 0; i <= 32; i++)
    {
        if (findIfKthBitSet(i, n))
        {
            ans = 1 << (32 - i) | ans;
        }
    }
    return ans;
}

int main()
{
    int num = 43261596;

    cout << endl;
    cout << reverseBits(num) << endl;
    return 0;
}

// SOME GITHUB SOL

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        // cout << numeric_limits<uint32_t>::max() << endl;
        // // return numeric_limits<uint32_t>::max() - n;
        // return numeric_limits<uint32_t>::max();
        uint32_t x = 0;
        int d = 0;
        while (n > 0)
        {
            // cout << d << " " << n << endl;
            x += (n % 2) << (31 - d);
            n >>= 1;
            d++;
        }
        return x;
    }
};
