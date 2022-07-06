#include <bits/stdc++.h>
#include<iostream>
using namespace std;
//topological sort on directed acyclic graphs only
/* what?-> Linear ordering of vertices such that for every edge u->v, u always apperas before v 
in that ordering. */


void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int> > &adj){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }
    //important logic
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    //create adj list
    //prepare adj list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        //graph is directed
        adj[u].push_back(v);
    }

    //call dfs topoligical sort util func for all copmponents
    //vector<bool> visited; bhi bna skte h for TLE, or time less hojayega (isko function argum me or change kr lena)
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        ans.pop_back();
    }
    return ans;
    
}