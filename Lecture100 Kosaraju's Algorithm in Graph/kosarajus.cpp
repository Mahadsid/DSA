#include <bits/stdc++.h>
#include<iostream>
using namespace std;
//for finding storngly connected components
// esa point jisko source manke hm sari node traverse krle(in directed graph)


void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, 
unordered_map<int, list<int>> &adj){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, st, adj);
        }
    }
    //topological logic
    st.push(node);
}

void revDFS(int node, unordered_map<int, bool> &vis, 
unordered_map<int, list<int> > &transpose){
    vis[node] = true;
    for(auto nbr : transpose[node]){
        if(!vis[nbr]){
            revDFS(nbr, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        //directed graph
        adj[u].push_back(v);
    }
    //topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            //dfs call
            dfs(i, vis, st, adj);
        }
    }
    //step 2 transpose graph
    unordered_map<int, list<int> > transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0; // bcz when we do dfs first time it gets updated so again intilize with zero
        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    //step 3  dfs on transpose graph
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            revDFS(top, vis, transpose);
        }
    }
    return count;
} //tc=0(N+E), sc=0(N)
