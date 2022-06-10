#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOnetwo(int arr[], int n) {

    int left = 0, right = n-1;

    while( left< right) {
        // if element is 0
        if (arr[left]==0)
        {
            
            left++;
        }
        else if (arr[right]==1)
        {
            right--;
        }
        else
        {
            swap(arr[left++], arr[right--]);
        }
        

    }

}


int main() {

    int arr[9] = {0,0,1,1,0,1,1,0,0};

    sortOnetwo(arr, 9);
    printArray(arr, 9);


    return 0;

}

    
