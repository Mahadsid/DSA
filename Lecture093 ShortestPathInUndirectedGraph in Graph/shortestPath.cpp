#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// bfs intiuation is,its give shortest path
vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t){
    //create adj list
    //prepare adj list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first; 
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, bool> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    //parent array is ready 
    //preapre shortest path
    vector<int> ans;
    int currentNode =  t; //t->destination node
    ans.push_back(t);
    while (currentNode != s)        
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}//tc=0(N+E), sc=0(N+E)