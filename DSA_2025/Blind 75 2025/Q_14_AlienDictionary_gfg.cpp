// STRIVER: https://youtu.be/U3N_je7tWAs?si=4bYKZcbNqM6BiB7q
/*
Example 1:
Input: N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output: b d a c
Explanation:
We will analyze every consecutive pair to find out the order of the characters. The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary. The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary. The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary. So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.


Example 2:
Input: N = 3, K = 3
dict = {"caa","aaa","aab"}
Output: c a b
Explanation: Similarly, if we analyze the consecutive pair for this example, we will figure out [‘c’, ‘a’, ‘b’] is a valid ordering.
*/
/*
Algorithm
Graph construction is done by comparing each consecutive pair of words.

Initial Setup
Adjacency List: Initially empty; built by comparing consecutive words.
Indegree Array: Stores incoming edges for each node, initially all 0.
Queue: Stores nodes with indegree 0 (BFS traversal starts from these).
Steps to Build the Graph
Loop through all words from index 0 to N-2 (compare word[i] with word[i+1]).
For each pair, compare characters up to the length of the smaller word.
On finding the first differing character (s1[x] ≠ s2[x]): Create a directed edge s1[x] → s2[x] and break the loop.
Topological Sort (BFS)
Calculate indegrees: For every edge u → v, increment indegree[v] by 1.
Push all nodes with indegree 0 into the queue.
While the queue is not empty:
Pop a node and add it to the answer list.
For each adjacent node v of u:
Reduce indegree[v] by 1.
If indegree[v] becomes 0, push it into the queue.
Repeat until the queue is empty.
Final Answer
Convert the numeric answer list to characters by adding ‘a’ to each index.
Return the final concatenated string as the alien dictionary order.
*/
#include <bits/stdc++.h>
using namespace std;

// Class to represent the solution
class Solution
{
private:
    // Function to perform Topological Sort using Kahn's Algorithm (BFS)
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // indegree[i] will store number of incoming edges for node i
        vector<int> indegree(V, 0);

        // Compute indegree of all vertices
        for (int i = 0; i < V; i++)
        {
            for (auto neighbor : adj[i])
            {
                indegree[neighbor]++;
            }
        }

        // Queue to store all vertices with indegree = 0
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo; // to store the topological order

        // Process until queue is empty
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Add this node to result
            topo.push_back(node);

            // For each neighbor, decrease its indegree
            for (auto neighbor : adj[node])
            {
                indegree[neighbor]--;
                // If indegree becomes 0, push it into the queue
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }

public:
    // Function to find the order of characters in the alien dictionary
    string findOrder(string dict[], int N, int K)
    {
        // Graph represented as adjacency list
        vector<int> adj[K]; // K are no of alphabets given in question; so here use vector<int> adj[K] for online submission for local env it gives error.

        // Build graph by comparing adjacent words in dictionary
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            // Find the first different character and create edge
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break; // only the first mismatch matters
                }
            }
        }

        // Perform topological sort on the graph
        vector<int> topo = topoSort(K, adj);

        // Convert numeric values back to characters
        string ans = "";
        for (auto node : topo)
        {
            ans += char(node + 'a');
        }

        return ans;
    }
};

// Driver Code
int main()
{
    // K are no of alphabets given in question;
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string ans = obj.findOrder(dict, N, K);

    // Print result
    for (auto ch : ans)
    {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}
/*
Complexity Analysis

Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.

Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency list used in the algorithm.) for the answer array and O(K) for the adjacency list used in the algorithm.
*/