#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOnetwo(int arr[], int n) {

    int left = 0, mid = 0, right = n-1;

    while( mid< right) {
        // if element is 0
        if (arr[mid]==0)
        {
            swap(arr[left], arr[mid]);
            left++;
            mid++;

        }
        else if (arr[mid]==1 && mid > 0)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[right--]);
        }
        
        
        


    }

}


int main() {

    int arr[9] = {0,2,2,1,0,1,1,0,2};
    int brr[3] = {2,0,1};
    int crr[2] = {1,2};

    sortOnetwo(arr, 9);
    printArray(arr, 9);

    sortOnetwo(brr, 3);
    printArray(brr, 3);

    sortOnetwo(crr, 2);
    printArray(crr, 2);


    return 0;

}

    
