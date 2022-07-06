#include <bits/stdc++.h>
#include<iostream>
using namespace std;


void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    //base case
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void uinonSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] <  rank[v]){
        parent [u] = v;
    }
    else if(rank[v] < rank [u]){
        parent[v] = u;
    }
    else{
        //both equal kisi ko bhi kisi ka prewnt bna skte h
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b){
    //owr own comparator to sort according to weight
    return a[2] < b[2];
}

int minSPTKruskal(vector<vector<int>> &edges, int n){
    //return int=> total weight of MST 
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);


    sort(edges.begin(), edges.end(), cmp);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        // same ignore, differnet -> union
        if(u != v){
            minWeight += wt;
            uinonSet(u, v, parent, rank);
        }
    }
    return minWeight;
}//tc=0(m log m), sc=0(n)