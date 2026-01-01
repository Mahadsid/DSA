/*
178: GRAPH VALID TREE
description:
Given n nodes labeled 0 to n-1 and a list of undirected edges(each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
Example 1:
Input n=5, edges =[[0,1], [0, 2],[0, 4],[1, 4]]
Output = true
*/
// https://youtu.be/bXsUuownnoQ?si=LvhzH_E_f2N0IPAg
// https://youtu.be/3Bc8IEtO8Dk?si=OTPZIPSFr8l1Jdru

#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &adgList, vector<bool> &visited, int node, int parent)
{
    visited[node] = true;         // mark current node visited
    for (int adj : adgList[node]) // check its adjacent nodes
    {
        if (!visited[adj]) // if they are not visited we visit them SO DFS CALL them, if visited so no ca ll
        {
            if (isCycle(adgList, visited, adj, node)) // node become parent & its adjcent node become new node
            {
                return true; // if anywhere we find cycle we send true, so validTree code can say false (it is not a valid tree)
            }
            else if (adj != parent)
            {
                return true; // if parent are different then cycle is present so return true
            }
        }
    }
    return false; // no cycle is present
}

bool validTree(int n, vector<vector<int>> &edges)
{
    if (edges.size() != n - 1) // quick edge count check: a tree must have exactly n-1 edges
        return false;
    vector<vector<int>> adjList(n); // build adjacency list
    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]); // add both directions (undirected)
        adjList[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);       // fasle=unvisited, true=visiting/visited
    if (isCycle(adjList, visited, 0, -1)) // if cycle is present return fasle that it is not a valid tree. 0-> root node/starting node, -1 -> root node has no parent so -1
        return false;
    for (bool v : visited) // second condn: if graph is disconnected, so it cannot be a valid tree, so after applying dfs above it should visit each node only if all node are connected,
    {
        if (!v) // if we get any node not visited that means graph is disconnected so it cannot be a valid tree return false.
            return false;
    }
    return true; // else both cond(no cycle & not disconnected) not match, then it is a valid tree
}