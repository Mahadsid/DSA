#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector < vector<int>> printAdj(int n, int m, vector<vector<int>> &edges){
    vector< vector<int> > ans;
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        //undirected graph
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector< vector<int> > adj;
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        
        //adding neighbours
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}