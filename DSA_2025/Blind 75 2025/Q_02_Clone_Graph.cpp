/*
133. Clone Graph
Medium

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


Example 1:

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:

Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/

// https://youtu.be/8qs4XEwIWSY?si=MO7CUuNevyrWlGRM
// https://youtu.be/mQeF6bN8hMk?si=7Oe8vDSVawMyLdy5

// Definition for a Node.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    // map to store original node -> cloned node mapping
    unordered_map<Node *, Node *> cloned;

    // DFS function to clone a graph
    Node *dfs(Node *node)
    {

        if (!node)
            return nullptr; // if null node, return null

        if (cloned.find(node) != cloned.end())
            return cloned[node]; // if already cloned, return cached copy

        Node *copy = new Node(node->val); // create clone of current node
        cloned[node] = copy;              // store mapping (original -> clone)

        for (Node *nbr : node->neighbors)
        {                                        // iterate all neighbors
            copy->neighbors.push_back(dfs(nbr)); // recursively clone neighbors
        }

        return copy; // return cloned node
    }

    Node *cloneGraph(Node *node)
    {
        return dfs(node); // cloning starts from given node
    }
};

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// DFS CODE EASY" https://youtu.be/mQeF6bN8hMk?si=7Oe8vDSVawMyLdy5
/*
EXPLANATION (Very Simple and Clear)
🔹 Key Idea

A graph may have cycles, so standard recursion would enter infinite loops.
So we need a map that remembers which nodes are already cloned.

original node → cloned node

🔹 Steps

1.If original node is NULL, return NULL.

2.If node already exists in map, return the stored clone.

3.Create a new clone node.

4.For each neighbor:
    -Recursively clone the neighbor

    -Add it to the clone’s neighbors list

5.Return the clone.

This ensures:
✔ No infinite recursion
✔ Every node cloned exactly once
✔ Graph structure fully preserved
Time: O(N + E)
Space: O(N)

Because we store a clone for each node exactly once.
*/
class DFS
{
public:
    unordered_map<Node *, Node *> copies;
    Node *cloneGraph(Node *node)
    {
        if (!node) // base cond edge case
            return NULL;
        if (copies.find(node) == copies.end()) // if node is already cloned or not
        {
            copies[node] = new Node(node->val, {}); // clone/copy it.
            for (Node *neighbor : node->neighbors)
            {
                copies[node]->neighbors.push_back(cloneGraph(neighbor)); // go on to neighbors of actual node to mark clone neighbors of cloned node.
            }
        }
        return copies[node];
    }
};