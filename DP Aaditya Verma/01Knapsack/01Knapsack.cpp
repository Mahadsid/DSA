#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//recursive code
int Knapsack(vector<int> wt, vector<int> val, int cap, int n){
    if(n==0 || cap == 0){
        return 0;
    }
    //item bag m tbhi ayega jb item ka wt cap s km ya = ho
    if(wt[n-1] <= cap){
        return max(val[n-1] + Knapsack(wt, val, cap-wt[n-1], n-1), Knapsack(wt, val, cap, n-1));
                //(item leliya to cap-item wt, smaller ip p call),(item NI liya to cap same, smaller ip p call)
    }
    else if(wt[n-1] > cap){
        return Knapsack(wt, val, cap, n-1); //(item NI liya to cap same, smaller ip p call)
    }
}

//memoisation
vector<vector<int>> mem(12, vector<int>(12, -1)); //from constraintss or jo var change hore h [n+1][cap+1];
int KnapsackMeMo(vector<int> wt, vector<int> val, int cap, int n){
    if(n==0 || cap == 0){
        return 0;
    }
    if(mem[n][cap] != -1){
        return mem[n][cap];
    }
    //item bag m tbhi ayega jb item ka wt cap s km ya = ho
    if(wt[n-1] <= cap){
        return mem[n][cap] = max(val[n-1] + KnapsackMeMo(wt, val, cap-wt[n-1], n-1), KnapsackMeMo(wt, val, cap, n-1));
                //(item leliya to cap-item wt, smaller ip p call),(item NI liya to cap same, smaller ip p call)
    }
    else if(wt[n-1] > cap){
        return mem[n][cap] = KnapsackMeMo(wt, val, cap, n-1); //(item NI liya to cap same, smaller ip p call)
    }
}

//Bottom up Tabulation
int KnapsackTaB(vector<int> wt, vector<int> val, int cap, int n){
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
                tab[i][j] = max( val[i-1] + tab[ i-1 ][j-wt[i-1]], tab[i-1][j] );
                //(item leliya to cap-item wt, smaller ip p call),(item NI liya to cap same, smaller ip p call)
            }
            else if(wt[i-1] > j){
                tab[i][j] = tab[i-1][j]; //(item NI liya to cap same, smaller ip p call)
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
    //Recursive 
    cout << Knapsack(wt, val, cap, n) << " = "<< "Recusive" << endl;
    //memoization
    cout << KnapsackMeMo(wt, val, cap, n) << " = " << "Memoization" << endl;
    //tabulation
    cout << KnapsackTaB(wt, val, cap, n) << " = " << "Tablulation" << endl;
    
    return 0;
}