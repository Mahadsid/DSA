#include<iostream>
using namespace std;

int sum(int arr[], int n){

    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;


}

int main(){
    int size;
    cin >> size;

    int num[20];

    //taking input in array
    for(int i = 0; i<size; i++) {
        cin >> num[i];
    }
    // printing array
    for(int i=0; i<size; i++) {
        cout << num[i] << " " ;
    }

    int ans = sum(num, size);
    cout<< "sum of array is = "<< ans << endl;


    return 0;
}