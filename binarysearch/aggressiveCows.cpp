#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<stalls.size(); i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    
   	int s = 0;
    int maxi = -1;
    for(int i=0; i<stalls.size(); i++) {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1; // quinki largest value nikalni h
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    vector<int> arr = {10,20,30,40};

    cout <<" Answer is " << aggressiveCows(arr, 2) << endl;

    return 0;
}
