/*
Problem Statement -

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2

*/

//Code -

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the root is null, the depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The depth of the tree rooted at the current node is the maximum depth
        // of its left and right subtrees, plus 1 for the current node itself.
        return 1 + max(leftDepth, rightDepth);
    }
};
