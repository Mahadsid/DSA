#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//rat in a maze problem 

bool isSafe(int newx, int newy,vector< vector< bool > > &vis, vector <vector<int>> &arr,
   int n){

       if( (newx >= 0 && newx < n ) && (newy >=0 && newy < n) &&
       vis[newx][newy] != 1 && arr[newx][newy] == 1 ){
           return true;
       }
       else{
           return false;
       }
}

void solve(int x, int y, vector <vector<int>> &arr, int n, vector<string> & ans,
    vector< vector< bool > > &vis, string path){

        //base case
        if(x == n-1 && y== n-1){
            //ans store kra lena h
            ans.push_back(path);
            return;
        }
        //4 movement D, L, R, U

        //Down movement row +1, col stays
        if(isSafe(x+1, y, vis, arr, n)){
            vis[x][y] = 1;
            solve(x+1, y, arr, n, ans, vis, path + 'D');
            //wapas ate time dubara zero for backtracking
            // when returning again make visited zero
            vis[x][y] = 0;
        }

        //Left movement row stays, col - 1
        if(isSafe(x, y-1, vis, arr, n)){
            vis[x][y] = 1;
            solve(x, y-1, arr, n, ans, vis, path + 'L');
            //wapas ate time dubara zero for backtracking
            // when returning again make visited zero
            vis[x][y] = 0;
        }

        //Right movement row stays, col + 1
        if(isSafe(x, y+1, vis, arr, n)){
            vis[x][y] = 1;
            solve(x, y+1, arr, n, ans, vis, path + 'R');
            //wapas ate time dubara zero for backtracking
            // when returning again make visited zero
            vis[x][y] = 0;
        }

        //UP movement row - 1, col stays
        if(isSafe(x-1, y, vis, arr, n)){
            vis[x][y] = 1;
            solve(x-1, y, arr, n, ans, vis, path + 'U');
            //wapas ate time dubara zero for backtracking
            // when returning again make visited zero
            vis[x][y] = 0;
        }
}

vector<string> searchMaze(vector <vector<int>> &arr, int n){
    vector<string> ans;
    vector< vector< bool > > vistied(n, vector<bool> (n,0));
    string path ="";

    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0, arr, n, ans, vistied, path);
    return ans;    
}
//tc= 0(4^n^2), sc=0(n*m)
