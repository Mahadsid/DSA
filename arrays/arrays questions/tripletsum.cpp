#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool tripletsum(int arr[], int n, int sum) {
   

     for(int i=0; i<n-2; i++ )
   {
   		for(int j = i+1; j< n-1; j++) {

               for (int k = j+1; k <= n-1; k++)               {
                   if(arr[i] +arr[j] + arr[k] == sum){
                       cout << "Triplet is " << arr[i] <<
                        ", " << arr[j] << ", " << arr[k]<< endl;
                        return true;

                   }
               }
        }
   }
   return false;

}



int main() {

    int arr[9] = {1, 4, 45, 6, 10, 8};
    int brr[5] = {1,3,2,4,5};
    int crr[2] = {1,2};

    tripletsum(arr, 9, 22);
    tripletsum(brr, 5, 5);


    return 0;

}