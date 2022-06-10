#include<iostream>
#include<vector>
using namespace std;

  
int find_pivot(int v[], int n)
{
	int s = 0, e = n - 1;
    int sumleft, sumright = 0;
	int mid=(s + e) / 2;
	while (s <= e)
	{
	for (int i = s; i < mid-1; i++)
    {
        sumleft=sumleft+v[i];

    }
    for (int j = mid+1; j <= e; j++)
    {
        sumright=sumright+v[j];

    }
    if (sumleft==sumright)
    {
        cout << "pivot is " << mid<< endl;
        return mid;
    }
  
    }
    return -1;

}

int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        cout<< sum<< endl;
        
        int lSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
            cout<<sum<<endl;
            if(sum == lSum) {
                return i;
            }
            lSum += nums[i];
            // cout<<lSum<< endl;
        }
        // cout<<"pivot is "<< i<< endl;
        return -1;
    }


int main(){
    int arr[6]={1,7,3,6,5,6};
    vector<int> brr  = {1,7,3,6,5,6};
    
    cout << pivotIndex(brr);

    // find_pivot(arr, 6);
    return 0;
}

