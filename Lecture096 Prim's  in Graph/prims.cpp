#include <bits/stdc++.h>
#include<iostream>
using namespace std;


vector<pair<pair<int, int>, int >> clacPrimsMST(int n, int m, 
vector<pair<pair< int, int>, int >> &g){
    //create adj list
    //for first int(node) k according dusra int(node) or uska weight (teesra int)
    unordered_map<int, list<pair<int, int> > > adj;

    for (int i = 0; i < g.size(); i++)
    {   
        //in question nodes are starting from 1 so its okay other wise add -1 in both u and v
        int u = g[i].first.first; //for zero mapping => int u = g[i].first.first -1;
        int v = g[i].first.second; //for zero mapping=> int v = g[i].first.second -1;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    //(n+1) bcz we asscociate index to node there is no zero node so n+1
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);  

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //start algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u ;
        //find the min wali node
        for (int v = 1; v <= n; v++)
        {
            if(mst[v] == false && key[v] < mini){
                u=v;
                mini = key[v];
            }
        }

        //mark min node as true
        mst[u] = true;

        //check its adj nodes
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    //int i=2 bcz no zero node & node 1 parent is -1 so that's why 
    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair( make_pair(parent[i], i), key[i]));
    }
    return result;
    
}//tc= 0(n^2)