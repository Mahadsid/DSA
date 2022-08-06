#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Partion string to make them palindrome -> worstcase afte every word partition

bool isPalindrome(string a) {
    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a[s] != a[e])
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

//Recursive
int MCMRec(string str, int i, int j){
    //Base Cond
    if(i >= j){
        return 0;
    }
    if(isPalindrome(str)){
        return 0;
    }
    int mini = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempans = MCMRec(str, i , k) + MCMRec(str, k+1, j) + 1;
       
        mini = min(tempans, mini);
        
    }
    return mini;
}

//TopDown Memo
int MCMMemo(string str, int i, int j){
    vector<vector<int>> t(str.size()+1, vector<int>(str.size()+1, -1));
    //Base Cond
    if(i >= j){
        return 0;
    }
    if(isPalindrome(str)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int mini = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempans = MCMMemo(str, i , k) + MCMMemo(str, k+1, j) + 1;
       
        mini = min(tempans, mini);
        
    }
    return t[i][j] = mini;
}
//optimization
int MCMMemoOPTI(string str, int i, int j){
    vector<vector<int>> t(str.size()+1, vector<int>(str.size()+1, -1));
    //Base Cond
    if(i >= j){
        return 0;
    }
    if(isPalindrome(str)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int mini = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int left, right;
        if(t[i][k] != -1){
            left = t[i][k];
        }
        else{
            left = MCMMemo(str, i , k);
        }
        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }
        else{
            right = MCMMemo(str, k+1 , j);
        }
        int tempans = left + right + 1;
       
        mini = min(tempans, mini);
        
    }
    return t[i][j] = mini;
}

int main(){
    string s = "nitik";
    int i = 1;
    int j = s.size() - 1;

    //Recursive
    cout << "Min Cuts Of String Palindrome (REC) = " << MCMRec(s, i , j) << endl;
    cout << "Min Cuts Of String Palindrome (MEMO) = " << MCMMemo(s, i , j) << endl;
    cout << "Min Cuts Of String Palindrome (OPTI) = " << MCMMemoOPTI(s, i , j) << endl;

}