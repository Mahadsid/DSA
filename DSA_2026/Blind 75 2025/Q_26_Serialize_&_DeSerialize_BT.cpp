/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

// STRIVER: https://youtu.be/-YbXySKJsX8?si=lR6kdZlRvVyHzox5
*/
// STRIVER SOL: https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree

/*
Complexity Analysis

Time Complexity: O(N)

serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.
deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.
Space Complexity: O(N)

serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.s
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize node value and child pointers
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform in-order traversal and print the tree
void inorder(TreeNode *root)
{
    // Base condition: if node is null, return
    if (!root)
    {
        return;
    }

    // Recursively traverse the left subtree
    inorder(root->left);

    // Print the current node's value
    cout << root->val << " ";

    // Recursively traverse the right subtree
    inorder(root->right);
}

class Solution
{
public:
    // Function to serialize a binary tree into a string using level-order traversal
    string serialize(TreeNode *root)
    {

        // If tree is empty, return an empty string
        if (!root)
        {
            return "";
        }

        // Initialize string to store serialized result
        string s = "";

        // Initialize a queue to store nodes during level-order traversal
        queue<TreeNode *> q;

        // Push root node into the queue
        q.push(root);

        // Loop while queue is not empty
        while (!q.empty())
        {

            // Get the current node from the front of the queue
            TreeNode *curNode = q.front();
            q.pop();

            // If current node is null, append "#" to string
            if (curNode == nullptr)
            {
                s += "#,";
            }
            else
            {
                // Append node value to string
                s += to_string(curNode->val) + ",";

                // Push left child into queue
                q.push(curNode->left);

                // Push right child into queue
                q.push(curNode->right);
            }
        }

        // Return the serialized tree string
        return s;
    }

    // Function to deserialize a string and reconstruct the binary tree
    TreeNode *deserialize(string data)
    {

        // If data is empty, return null
        if (data.empty())
        {
            return nullptr;
        }

        // Use stringstream to parse the input data
        stringstream s(data);
        string str;

        // Read the root value from the stream
        getline(s, str, ',');

        // Create the root node
        TreeNode *root = new TreeNode(stoi(str));

        // Initialize a queue to hold tree nodes for level-order reconstruction
        queue<TreeNode *> q;

        // Push root node into the queue
        q.push(root);

        // Loop through the stream to construct the tree
        while (!q.empty())
        {

            // Get the current node from the front of the queue
            TreeNode *node = q.front();
            q.pop();

            // Read the left child value
            getline(s, str, ',');

            // If value is not "#", create left node and attach to current node
            if (str != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the right child value
            getline(s, str, ',');

            // If value is not "#", create right node and attach to current node
            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the root of the reconstructed tree
        return root;
    }
};

// Driver code
int main()
{

    // Manually construct the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Create an instance of the solution class
    Solution solution;

    // Print original tree using in-order traversal
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    // Serialize the tree into a string
    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    // Deserialize the string back into a tree
    TreeNode *deserialized = solution.deserialize(serialized);

    // Print tree after deserialization
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}