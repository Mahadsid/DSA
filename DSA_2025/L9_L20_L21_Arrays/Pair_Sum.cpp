/*
You are given an integer arrray 'arr' of size 'n' and an integer for example '5'. You task is to return the list of all pairs of elements such as that each sum of elements of each par equals '5'.

Each pair should be sorted, i.e. the first value should be less than or equal to the second value.
return the list of pairs sorted in non-decreasing order of their first value. incase if two pairs have same first value, the pair with a smaller second value should come first.
*/

//+++++++++ Brute force +++++++++
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;
#include <vector>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

//+++++++++++ BRUTE FORCE +++++++++++++++
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pairSum1(vector<int> &arr, int target)
{
    vector<pair<int, int>> result; // to store valid pairs

    // Compare every element with every other element
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            // If sum equals target
            if (arr[i] + arr[j] == target)
            {

                int a = min(arr[i], arr[j]); // ensure smaller comes first
                int b = max(arr[i], arr[j]); // ensure larger second
                result.push_back({a, b});    // store the pair
            }
        }
    }

    // Sort pairs: first by first element, then by second element
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 2, 3};
    int target = 5;

    vector<pair<int, int>> ans = pairSum1(arr, target);

    // Print all pairs
    for (auto &p : ans)
        cout << "(" << p.first << "," << p.second << ") ";

    return 0;
}

/*
🕒 Time Complexity: O(n²)
📦 Space Complexity: O(k) for storing pairs
✅ Works correctly but slow for large arrays.
*/

// ++++++++++++++ BETTER APPROACH USING HASH MAP+++++++++

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pairSum2(vector<int> &arr, int target)
{
    unordered_map<int, int> freq;  // store count of elements
    vector<pair<int, int>> result; // store valid pairs

    // Count occurrences of each number
    for (int num : arr)
        freq[num]++;

    // Traverse array
    for (int num : arr)
    {
        int complement = target - num; // find what number can pair with current one

        // If complement exists in map
        if (freq[complement] > 0)
        {

            // Check if same number and there are at least 2 occurrences
            if (num == complement && freq[num] < 2)
                continue;

            // Otherwise, add the pair (sorted)
            result.push_back({min(num, complement), max(num, complement)});

            // Reduce frequencies to avoid duplicates
            freq[num]--;
            freq[complement]--;
        }
    }

    // Sort pairs as required
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 2, 3};
    int target = 5;

    vector<pair<int, int>> ans = pairSum2(arr, target);

    for (auto &p : ans)
        cout << "(" << p.first << "," << p.second << ") ";

    return 0;
}

/*
🕒 Time Complexity: O(n log n)   (for sorting)
📦 Space Complexity: O(n)
✅ Faster and uses hashing for counting.
*/

//++++++++++ BEST APPR- TWO POINTER
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pairSum3(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());  // sort array for two-pointer method
    vector<pair<int, int>> result; // to store all valid pairs

    int left = 0, right = arr.size() - 1; // two pointers

    while (left < right)
    {                                     // loop until pointers cross
        int sum = arr[left] + arr[right]; // calculate current sum

        if (sum == target)
        {                                              // if pair found
            result.push_back({arr[left], arr[right]}); // store pair
            left++;                                    // move both pointers
            right--;
        }
        else if (sum < target) // if sum too small
            left++;            // increase left to get bigger sum
        else                   // if sum too big
            right--;           // decrease right to get smaller sum
    }

    return result; // return sorted pairs
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 2, 3};
    int target = 5;

    vector<pair<int, int>> ans = pairSum3(arr, target);

    for (auto &p : ans)
        cout << "(" << p.first << "," << p.second << ") ";

    return 0;
}

/*
🧩 Explanation:
- Sort array first → enables two-pointer traversal.
- Move pointers based on current sum comparison with target.
- Collect all valid pairs (sorted naturally).

🕒 Time Complexity: O(n log n)
📦 Space Complexity: O(1)
✅ Clean, efficient, and ideal for interviews.
*/

// +++++++++++ TRIPLET SUM++++++++++++
#include <set>

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    // Set to keep the track of visited triplets.
    set<vector<int>> visited;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // If we find a valid triplet.
                if (arr[i] + arr[j] + arr[k] == K)
                {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);
                    // Sorting the triplet track distinct triplets.
                    sort(triplet.begin(), triplet.end());
                    if (visited.find(triplet) == visited.end())
                    {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }

    return ans;
}