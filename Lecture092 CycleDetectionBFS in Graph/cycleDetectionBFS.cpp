#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//directed graph
/* khans algo -> bfs -> topological sort -> directed acyclic graph
                        invalid topological sort -> cyclic grapg (or we say cycle present)*/

int detectCycleInDirectedGraph(int n, vector<pair < int,int>> &edges){
    //create adj list
    //prepare adj list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first -1; //-1 bcz in question nodes starting from zero
        int v = edges[i].second -1;
        //graph is directed
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(n);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    // 0 indegrree push in queue
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //do bfs
    int cnt = 0;
    while (!q.empty()){
        int front = q.front();
        q.pop();

        //inc count
        cnt++;
        //neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(cnt == n){
        return false; //cycle is not present bcz cnt == nodes DAG == nodes
    }
    else{
        return true; // cycle is present
    }
}//tc & sc = same