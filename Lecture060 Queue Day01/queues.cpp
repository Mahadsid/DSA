#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;


// fifo 
/*  push -> rear, pop -> front*/


//implement queue

class  Queue{

    //properties
    int *arr;
    int qfront;
    int qrear;
    int size;

    //functions / behaviours
    Queue(){
        size = 10001;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    void enQueue(int element) {
        if (qrear == size)
        {
            cout << "QUEUE is full" << endl;
        }
        else{
            arr[qrear] == element;
            qrear++;
        }
        
    } 
    int deQueue() {
        if (qfront == qrear)
        {
            cout << "QUEUE is empty" << endl;
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if (qfront ==  qrear)
            {
                qfront = 0;
                qrear = 0;
            } 
            return ans;   
        }  
    } 
    int front() {
        if (qfront == qrear)
        {
            cout << "QUEUE is empty" << endl;
            return -1;
        }
        else{
            return arr[qfront];
        }
            
    }  
    bool isEmpty(){
        if (qfront == qrear)
        {
            cout << "QUEUE is empty" << endl;
            return true;
        }
        else
            return false;
    }
        
};

int main(){
    queue<int> q;

    q.push(5);
    q.push(15);
    q.pop();

    cout <<  q.size() << endl;
    cout << q.empty() << endl;
    cout << q.front() << endl; //same as top (element at first)

    
    
    return 0;
}