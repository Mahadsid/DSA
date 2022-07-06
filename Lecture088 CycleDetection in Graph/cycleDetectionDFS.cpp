#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool isCyclicDFS(int node, int parent,  unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
           bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycleDetected){
                return true;
            }
            else if(neighbour != parent){
                //cycle is present
                return true;
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
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}