class Solution
{
public:
    int hammingWeight(int n)
    {

        int count = 0;
        while (n != 0)
        {

            // checking last bit
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

/*
example k liy 11 ka binaru diya hoga usme count krna h kitni set ya bits one h.

to hamne chalya count krenege so 1&1 = 1 hota h baki sb zero so ""and"" krne pr 1 s ans 1 hota h, to binary liya or ans 1 aya to count bdha do, next check kre k liy right shift krdo.!

*/