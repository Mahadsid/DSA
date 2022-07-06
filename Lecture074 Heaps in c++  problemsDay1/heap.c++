#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size = 0;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){ // tc= 0(logn)
            size = size +1;
            int index = size;
            arr[index] = val;

            while (index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return ;
                }

            }
        }
        void print(){
            for(int i =1; i<=size; i++){
                cout <<  arr[i] << "";
                cout << endl;
            }
        }
        void deleteFromHeap(){
            if(size == 0 ){
                cout << "nothing to delete";
                return;
            }

            arr[1] = arr[size];
            size--;
            //satisfy max heap property
            int i =1;
            while (i<size)  
            {
                int leftindex = 2*i;
                int rightindex = 2*i+1;

                if(leftindex < size && arr[i] < arr[leftindex]){
                    swap(arr[i], arr[leftindex]);
                    i = leftindex;
                }
                else if(rightindex < size && arr[i] < arr[rightindex]){
                    swap(arr[i], arr[rightindex]);
                    i = rightindex;
                }
                else{
                    return;
                }//tc=0(logn)
            }
            
        }
};


//FOR 1 BASE INDEXING 
void heapify(int arr[], int n, int i){ //tc=0(logn)
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left <= n && arr[largest] < arr[left]){
        largest = left;    
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;    
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    heap h;
    h.insert(50);

    //heap creation
    /*
    for 1 base indexing 
    for(int i = n/2; i>0; i--){ these are non leaf node
        heapify(arr, n, i);
    }

    for 0 base indexing 
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    */
}