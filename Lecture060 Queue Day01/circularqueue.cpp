#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;


// fifo 
/*  push -> rear, pop -> front*/


//implement queue

class  CircularQueue{

    //properties
    int *arr;
    int qfront;
    int qrear;
    int size;

    //functions / behaviours
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    bool enQueue(int element) {
        if ( (qfront == 0 && qrear == size -1) || ( qrear == (qfront-1)%(size-1) ) )
        {
            cout << "QUEUE is full" << endl;
            return false;
        }
        else if (qfront == -1 )// first element aya h push k liy
        {
            qfront = qrear = 0;
            
        }
        else if (qrear == size-1 && qfront!=0 )// first element aya h push k liy
        {
            qrear = 0;// to maintaim cyclic nature
            
        }
        else{//normAL FLOW
            qrear++;
        } 
        arr[qrear] = element;
        return true;
    } 

    int deQueue() {
        if (qfront == -1)
        {
            cout << "QUEUE is empty" << endl;
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;

        if(qfront == qrear){// single element in quer
            qfront == qrear == -1;  
        }

        else if (qfront ==  size-1)
        {
            qfront = 0; // to maintaim cyclic nature
        }
        else{//normal flow
            qfront++;
        }
        return ans;
          
    } 
        
};