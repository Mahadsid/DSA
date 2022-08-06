#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool Solve(string a, string b){
    if(a.length() != b.length()){return false;}
    if(a.empty()){return true;}
    if(b.empty()){return true;}
    if(a.compare(b) == 0){return true;} //zero swap
    if(a.length() <= 1){return false;}

    int n = a.length();
    bool flag = false;
    for(int i = 1; i<n; i++){
        if( 
        ( (Solve(a.substr(0,i), b.substr(n-i, i))) && (Solve(a.substr(i,n-i), b.substr(0, n-i))) ) 
        ||
        ( (Solve(a.substr(0,i), b.substr(0, i)) ) && (Solve(a.substr(i,n-i), b.substr(i, n-i)) ) )
        ){
            flag = true;
            break;
        }
    }
    return flag;
}


//memoization
unordered_map<string,bool> mp;
bool isScramble(string a, string b) {
    if(a.compare(b)==0)
        return true;
    if(a.size()<=1)
        return false;
    string key=a;
    key.push_back(' ');
    key.append(b);
        
    if(mp.find(key)!=mp.end())
        return mp[key];
        
    int n=a.size();
    bool flag=false;
        
    for(int i=1;i<n;i++)
    {
        if((isScramble(a.substr(0,i),b.substr(n-i,i))  && isScramble(a.substr(i,n-i),b.substr(0,n-i)))
            ||
            (isScramble(a.substr(0,i),b.substr(0,i))  && isScramble(a.substr(i,n-i),b.substr(i,n-i)))) {
            flag=true;
            break;
        }
    }
        
    return mp[key]=flag;
}

int main(){
    string a = "great";
    string b = "rgeat";
    int n = a.length();
    int m = b.length();

    //Recursive
    cout << "Scramble Strings (REC) = " << Solve(a, b) << endl;
    //memo
    cout << "Scramble Strings (MEMO) = " << isScramble(a, b) << endl;

}