/*

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
 
*/

//Code-

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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If the root is null, or root is p or q, then root is the LCA.
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Search for LCA in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search for LCA in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, the current root is the LCA.
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Otherwise, return the non-null child (if one subtree contains both p and q, the LCA is in that subtree)
        return (left != nullptr) ? left : right;
    }
};
