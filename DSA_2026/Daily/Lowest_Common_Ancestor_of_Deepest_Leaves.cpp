/*
865. Smallest Subtree with all the Deepest Nodes
Medium
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.


Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.

*/

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ylpPcln87hI
    Company Tags                : Meta, Amazon, Google, Bloomberg
    Leetcode Link               : https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/ (Leetcode 1123)
    Same Question on Leetcode   : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/ (Leetcode 865)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Approach-1 (Using 2 Pass Solution and LCA code)
// T.C : O(2*n) ~= O(n)
// S.C : O(maxDepth) System stack space
class Solution
{
public:
    unordered_map<int, int> mp;
    int maxD = 0;

    TreeNode *LCA(TreeNode *root)
    {
        // Agar root MAX-DEPTH ka h to return krdo upar ki wo traverse ho ke bata de uska ancestor kon h
        if (root == NULL || mp[root->val] == maxD)
        { // one extra condn only
            return root;
        }
        // LEFT RIGHT M DHUNDO
        TreeNode *l = LCA(root->left);
        TreeNode *r = LCA(root->right);
        // DONO MILGYE TO JIS ROOT P KHDE H USKO RETURN KRDO WO
        // ANS(LOWEST COMMON ANCESTOR) HOGA.
        if (l && r)
        {
            return root;
        }
        // AGAR EK NULL BHI HUA KOI BAAT NI, JO NULL NI H USKO RETURN KRDO
        return l != NULL ? l : r;
    }

    void depth(TreeNode *root, int d)
    {
        if (!root)
        { // Root hi ni h to return krdo
            return;
        }
        // maxD variable m max tree ki depth store kra lo
        maxD = max(maxD, d);
        mp[root->val] = d;        // map m root k according depth store krte chale ex, node-depth 3-1,
        depth(root->left, d + 1); // recursive call left right k liy
        depth(root->right, d + 1);
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        // 1. Depth nikal lo map or recursive call krke
        // 2. uske sath hi maxDepth pata kr lo ek variable bna k, ki tree ki kitni depth h
        depth(root, 0);
        // Step3. Max-Depth aagyi to iske  hisab s depth-nodes tk pohuch jao
        // Step4. Waha s same LCA wala call krdo
        // NOTE : IS QUES M 236. Lowest Common Ancestor of a Binary Tree ki ek condition
        // jo if case m lagai h wo jyada h, pr wo condition lagane k liy depth find krne ka code likhna pdega
        return LCA(root);
    }
};

////+++++++++++++++++++ APPROCH 2 O(N)++++++++++++++++++++++++++++
pair<int, TreeNode *> solve(TreeNode *root)
{
    if (root == NULL)
    {                     // Base case
        return {0, NULL}; // kuch ni h to return NULL
    }

    // step1. left right call, iske baad ans agya hoga
    auto l = solve(root->left);
    auto r = solve(root->right);
    // Step2. Agar dono side s depth same h to common h to return krdo woi common ancestor h
    // to us root p jispe khade ho return krdo depth bhi bda dena
    if (l.first == r.first)
    {
        return {l.first + 1, root};
    }
    // Step3. Since lowest Depth chaiye to jis side se jayada depth aaye woi node return jane do
    else if (l.first > r.first)
    { // left side s jo node ara h jyada depth leke usko upar pass krdo common dhundne k liy ek depth bda k
        return {l.first + 1, l.second};
    }
    else
    { // agar right s jayada depth leke node ara h to jane do common dhudne upar, depth bda k upar bhj do
        return {r.first + 1, r.second};
    }
}
TreeNode *subtreeWithAllDeepest(TreeNode *root)
{
    /*
    Ham ek pair bna lenge <depth, root> jo hr step p depth batayega
    depth niche root s kitni h
    */
    return solve(root).second;
}
