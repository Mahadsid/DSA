// LEETCODE 852.
// TC O(lon N )
#include <vector>
using namespace std;

class Solution
{
public:
    int find_pivot(vector<int> v)
    {
        int s = 0, e = v.size() - 1;
        int mid = (s + e) / 2;
        while (s < e)
        {
            if (v[mid] < v[mid + 1])
                s = mid + 1;
            else
                e = mid;

            mid = (s + e) / 2;
        }
        return s;
    }
    int peakIndexInMountainArray(vector<int> &arr)
    {
        return find_pivot(arr);
    }
};

/*

     / \
    /   \
   /     \
  /       \
 s        e


  this is the mountain which is represented by numbers in array like [2, 3, 5, 10, 6, 4, 1]

      cond 1:
  the left line cond is (v[mid] < v[mid + 1])
  if we take mid and it come out as less than its one graeter number that means we are on left line so make/update start s = mid + 1;

    cond 2:
  else case for above cond is we are on right side OR can be at peak.
  so either way we update end so e = mid;
  here we dont do e = mid - 1 as in Binary Search bcz doing -1 we can go on left side of array/mountain and can miss peak element.

    ***So both time we update end = mid so we dont miss mid/peak while updating!


*/