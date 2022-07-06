#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}   

void bfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, 
        vector<int> &ans, int node){
        
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        //store front node to ans
        ans.push_back(frontNode);

        //traverse all neighbours and push them to queue if not visited
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1; //make its visited true.
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    //adj list
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components of a graph (for disconn graph)
    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

// for ans in sorted way use set instead of list use insert fuction of set to insert else remain same
//tc=0(N+E) N=vertex = E = Edges