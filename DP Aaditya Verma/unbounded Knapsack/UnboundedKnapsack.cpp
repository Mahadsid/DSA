#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// multiple occurences can be allowed 
// if element not taken = processed (not taken anytime)

int UnKnapsackTaB(vector<int> wt, vector<int> val, int cap, int n){
    if(n==0 || cap == 0){
        return 0;
    }
    // Base condition ko hi initialization m change hojati h n=0 so zero row m full(0); zero col/cap = full(0)
    vector<vector<int>> tab(5, vector<int>(8));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < cap+1; j++)
        {
            if(i==0 || j==0){
                tab[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for (int j = 1; j < cap+1; j++)
        {   
            //item bag m tbhi ayega jb item ka wt cap s km ya = ho
            if(wt[i-1] <= j){
                tab[i][j] = max( val[i-1] + tab[ i ][j-wt[i-1]], tab[i-1][j] );
                //(item leliya (but tab [i] = wapas bhi le skte h(dubara n p call krdiya)) ;to cap-item wt, smaller ip p call),
                //(item NI liya to cap same, smaller ip p call)
            }
            else if(wt[i-1] > j){
                tab[i][j] = tab[i-1][j]; 
            }      
        }
    }
    return tab[n][cap];
}

int main(){
    vector<int> wt = {2,3,4,5};
    vector<int> val = {1,4,5,2};
    int cap = 7;
    int n = 4;

    cout << UnKnapsackTaB(wt, val, cap, n) << " = " << "Tablulation" << endl;
    
    return 0;
}

