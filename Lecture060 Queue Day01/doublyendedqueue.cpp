#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;


// fifo 
/*  push -> rear, pop -> front*/


//implement queue

class  DoubleEndedQueue{

    //properties
    int *arr;
    int qfront;
    int qrear;
    int size;

    //functions / behaviours
    DoubleEndedQueue(int n){
        size = n;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    bool pushFront(int element) {
        if ( (qfront == 0 && qrear == size -1) || ( qrear == (qfront-1)%(size-1) ) )
        {
            cout << "QUEUE is full" << endl;
            return false;
        }
        else if (qfront == -1 )// first element aya h push k liy
        {
            qfront = qrear = 0;
            
        }
        else if (qfront==0 && qrear != size-1)// first element aya h push k liy
        {
            qfront = size-1;// to maintaim cyclic nature
            
        }
        else{//normAL FLOW
            qfront--;
        } 
        arr[qfront] = element;
        return true;
    } 

    bool pushRear(int element) {
        if ( (qfront == 0 && qrear == size -1) || ( qrear == (qfront-1)%(size-1) ) )
        {
            cout << "QUEUE is full" << endl;
            return false;
        }
        else if (qfront == -1 )// first element aya h push k liy
        {
            qfront = qrear = 0;
            
        }
        else if (qrear == size-1 && qfront != 0  )// first element aya h push k liy
        {
            qrear = 0;// to maintaim cyclic nature
            
        }
        else{//normAL FLOW
            qrear++;
        } 
        arr[qrear] = element;
        return true;
    } 

    int popFront() {
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

    int popRear() {
        if (qfront == -1)
        {
            cout << "QUEUE is empty" << endl;
            return -1;
        }
        int ans = arr[qrear];
        arr[qrear] = -1;

        if(qfront == qrear){// single element in quer
            qfront == qrear == -1;  
        }

        else if (qrear == 0)
        {
            qrear = size-1; // to maintaim cyclic nature
        }
        else{//normal flow
            qrear--;
        }
        return ans;    
    } 

    int getFront() {
        if (isEmpty())
        {
            cout << "QUEUE is empty" << endl;
            return -1;
        }
        else{
            return arr[qfront];
        }
            
    }
    int getRear() {
        if (isEmpty())
        {
            cout << "QUEUE is empty" << endl;
            return -1;
        }
        else{
            return arr[qrear];
        }
            
    }  
    bool isEmpty(){
        if (qfront == -1)
        {
            cout << "QUEUE is EMPTY" << endl;
            return true;
        }
        else
            return false;
    }
    bool isFull(){
        if ((qfront == 0 && qrear == size -1) || (qfront !=0 && qrear == (qfront-1)%(size-1) ))
        {
            cout << "QUEUE is FULL" << endl;
            return true;
        }
        else
            return false;
    }
        
};


int main(){
    deque<int> d;

    d.push_front(12);
    d.push_back(14);


    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front(); 
    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();

    if (d.empty())
    {
        cout << " queue is empty" << endl;
    }
    else{
        cout << "que is not empty" << endl;
    }
    
    return 0;
}