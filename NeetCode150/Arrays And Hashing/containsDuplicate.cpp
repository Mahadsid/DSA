#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool hasDuplicate(vector<int> &nums)
{
    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);
    }

    return false;
}

int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // v.push_back(12);

    bool ans = hasDuplicate(v);

    cout << "Soln" << endl;
    cout << (ans);

    return 0;
}