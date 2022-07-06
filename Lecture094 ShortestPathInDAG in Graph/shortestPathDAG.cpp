#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int weight){
        pair<int,int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i : adj){
            cout << i.first << " ->";
            for(auto j: i.second){
                cout << "[" << j.first << "," << j.second << "], "; 
            }cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo){
        dist[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
        
    }
};

//tc=0(N+E), sc=0(n+e)
int main(){
    Graph g;

    int n=6; //acc to question
    //topological sort func
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    
    g.getShortestPath(src, dist, s);

    cout << "answer is:" << endl;

    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }cout << endl;
    
    return 0;
}
