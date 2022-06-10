#include<bits/stdc++.h>
#include<vector>
using namespace std;
using std::cout; using std::endl;
using std::vector;


vector<int> findDuplicate(vector<int> &arr) 
{
    vector<int> ans;
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size()-1; i++)
    {
        if (arr[i]==arr[i+1]){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5,2,3,8,9,5};
    vector<int> arrdup;

    arrdup = findDuplicate(arr);
    for(int i=0;i<arrdup.size();i++) {
        cout<<arrdup[i]<<" ";

    }



    return EXIT_SUCCESS;
}