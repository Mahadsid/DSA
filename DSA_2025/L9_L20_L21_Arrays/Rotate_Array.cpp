#include <iostream>
#include <vector>
using namespace std;

// Rotate array by "k" place
/*
example [-1, -100, 3, 99] k= 2 output=[3, 99, -1, -100]
*/

vector<int> rotate(vector<int> &nums, int k)
{

    // just to practice the modulus approach
    int n = nums.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        // cyclic way m K position s shift krna = this formula
        temp[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i]; //  temp ka array overwrite na ho is liy liya
    }
    return nums;
}

void print(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> v;

    v.push_back(9);
    v.push_back(11);
    v.push_back(1);
    v.push_back(7);
    // v.push_back(12);

    vector<int> ans = rotate(v, 2);

    cout << "Printing rotatted Array" << endl;
    print(ans);

    return 0;
}