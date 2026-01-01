/*
Leetcode 88:
question is merge sorted arrays;
for example input is nums1 =[1,2,3,0,0,0] m = 3 and nums2 = [2,5,6], n=3, output  =[1,2,2,3,5,6], explanation the array we are merging is [1,2,3] and [2,5,6]  the result of merge is [1,2,2,3,5,6]  with the underline elements comes from nums1.
Basically i think the 0s are just empty spaces dont consider them also the first  array size is given as 3. so what you say?
example 2: nums1=[1] m=1 and nums2=[] n=0, output =[1]
example 3: nums1=[0] m= 0 and nums2=[1] n=1, output= [1]
so solve this question.
*/

//+++++++++++++++++++++++++++++++++++++++++ OPTIMAL APPROACH: THREE POINTER FROM END +++++++++++++++++++++++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // pointer at end of valid nums1 elements
    int j = n - 1;     // pointer at end of nums2
    int k = m + n - 1; // pointer at end of nums1 full array

    // merge from the back of both arrays
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])     // if nums1 element is bigger
            nums1[k--] = nums1[i--]; // place nums1 element at end
        else
            nums1[k--] = nums2[j--]; // place nums2 element at end
    }

    // copy leftover nums2 elements (if any)
    while (j >= 0)
    {
        nums1[k--] = nums2[j--]; // fill remaining nums2 items
    }

    // no need to copy nums1 leftovers since they are already in place
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    mergeArrays(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";
    // Output: 1 2 2 3 5 6

    return 0;
}

/*
| Operation | Complexity                |
| --------- | ------------------------- |
| Time      | O(m + n)              |
| Space     | O(1) (in-place merge) |

*/