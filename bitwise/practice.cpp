#include<iostream>
using namespace std;

int main(){
    int a, b = 1;

    a = 10;
    if (++a)
    {
        /* code */
        cout<< b <<" in if "<<endl;
    }
    else{
        cout<< ++b << "in else"<<endl;
    }

    int num = 3;
    cout<< (25*(++num))<<endl;

    int x =1;
    int y=x++;
    int z=++x;
    cout<< y<< endl;
    cout<< z<< endl;

}