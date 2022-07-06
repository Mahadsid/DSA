#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Kahn's algorithm->BFS (queue used)
/* 1. find indegree of all nodes
2. make queue and put all 0 degree nodes in it
3. do BFS */

vector<int> topologicalSort(vector<vector<int>> & edges, int v, int e){
//create adj list
    //prepare adj list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        //graph is directed
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree;
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    // 0 indegrree push in queue
    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //do bfs
    vector<int> ans;
    while (!q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}
//tc=0(N+E), sc=0(N+E) linear

