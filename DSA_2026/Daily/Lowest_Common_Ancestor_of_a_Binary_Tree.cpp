/*
236. Lowest Common Ancestor of a Binary Tree
Medium
Topics
premium lock icon
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
   MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Oi3_06ultic
   Company Tags                : Accolite, Amazon, American Express, Expedia, MakeMyTrip, Microsoft, Payu, Snapdeal, Times Internet, Twitter
   Link to Qn                  : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        // MILGYA P & Q TO root KO RETURN KRDO UPAR
        if (root->val == p->val || root->val == q->val)
            return root;
        // LEFT RIGHT M DHUNDO P & Q KO
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        // DONO P & Q MILGYE TO JIS ROOT P KHDE H USKO RETURN KRDO WO
        // ANS(LOWEST COMMON ANCESTOR) HOGA.
        if (l != NULL && r != NULL)
            return root;

        // AGAR EK NULL BHI HUA KOI BAAT NI, JO NULL NI H USKO RETURN KRDO
        if (l != NULL)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
};