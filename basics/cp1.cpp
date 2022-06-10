#include<iostream>
using namespace std;

int main(){
    char ch;
    cin.get(ch);

    if (ch>=97 && ch <=122)
    {
        cout<<"small case";
    }
    else if (ch >= 65 && ch <=90)
    {
        cout<<"upper case";
    }
    else if (ch >= 48 && ch<=57)
    {
        cout<<"numeric";
    }
    else{
        cout<<"special char";
    }

    
}