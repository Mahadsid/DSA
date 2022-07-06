#include <bits/stdc++.h>
#include<iostream>
using namespace std;


bool checkCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited,
    unordered_map<int, list<int> > &adj){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected = checkCycle(neighbour, visited, dfsVisited, adj);
                if(cycleDetected){
                    return true;
                }
            else if(dfsVisited[neighbour]){
                //visited ara h to bs dfsVisited wali condition check krlo
                //visited->true && dfsVisited also->true cycle present
                return true;
            }
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int >> &edges){
    //create adj list
    //prepare adj list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        //only for u bcz directed graph
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    //call dfs for all components
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            bool cycleFound = checkCycle(i, visited, dfsVisited, adj);
            if(cycleFound){
                return true;
            }
        }
    }
    return false;
}