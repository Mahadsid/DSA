#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true; // cycle is present
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }        
    }
    return false;
}

string cycleDetectionBFS (vector<vector<int>> &edges, int n, int m){
    //create adj list
    //prepare adj list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    unordered_map<int, bool> visited;
    //to handle dis conn component
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}