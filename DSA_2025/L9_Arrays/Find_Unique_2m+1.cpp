/*
You have been given an integer arraylist of size N, where N is equal to 2m+1 (Personal Note: since it is 2m+1 that means it is odd array bcz 2m become even +1 makes it odd size).
Now in the given arraylist. 'm' numbers are present twice and one number is present only once.
You need to find and return that number which is unique is that array.
ex 'm' numbers are = 2 3 4 so len=7 and 'm' no's are present twice so array would look like some thing [2, 3, 2, 4, 3, 4, 9] and one unique no in this casae 9, find that
*/

/*

SOLUTION LOGIC
In maths we do like 5 + 2 - 2 - 5 + 3 = ans would be 3!
bcz +5 -5, +2 -2 cancel each other.

so this property also lies in XOR
if you XOR a with a it will result 0, or in simple terms cancel each other, the remaing we get is the ans.
XOR = a^a=0
also xor a^0 = a

DRY RUN
arr = [1 3 4 1 3]
1 xor 1 = 0 3 xor 3 = 0 so at last 0 xor 0 xor 4 result in 4 we get our ans.
*/

int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}