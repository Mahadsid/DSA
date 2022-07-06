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


void heapify(vector<int> &arr, int n, int i){ //tc=0(logn)
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left <= n && arr[smallest] > arr[left]){
        smallest = left;    
    }
    if(right <= n && arr[smallest] > arr[right]){
        smallest = right;    
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }

}//tc=0(n)


// Heap Sort
void heapSort(vector<int> arr, int n){
    int size = n;
    while (size > 1)
    {
        //step 1 swap
        swap(arr[size], arr[1]);
        //step2
        size--;

        heapify(arr, n, 1);
    }
    
}

vector<int> buildMinHeap(vector<int> &arr){
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}


//using pririoty queue
priority_queue<int> pq; //Max heap in nature

//min heap

priority_queue<int, vector <int>, greater<int> > minheap;


