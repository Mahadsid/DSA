#include <bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;

/* max with of a bar  = next - prev - 1 
where next = jb tk wo bar k right m smallest ya ni miljata uska index
and prev = left m small ni miljata uska index
equal m jayega 
or area = length * breadth 
length constt di h breadth nikal lo hr ek bar k liy upar wale logic s or multiply krlo
*/

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];
        while (s.top()!= -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);  
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        while (s.top()!= -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);  
    }
    return ans;
}


int largestRectangle(vector<int> & heights){
    int n = heights.size();
    
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        

        if (next[i]== -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] -1;
        int newArea = l*b;

        area = max(area, newArea);
    }
    //return accumulate(heights.begin(), heights.end(), 0) - area ;  codevita
    return area;

}

//tc= 0(n) sc=0(n)..

int main(){
    vector<int> heights = {6,7,3,4,5,1,3};
    vector<int> heights1 = {1,2,6,4,5,3,4};
    int ans = largestRectangle(heights);
    cout << ans << endl;

    int ans1 = largestRectangle(heights1);
    cout << ans1 << endl;

    return 0;
}