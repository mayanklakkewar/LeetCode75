/*

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:


Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0

*/

//Code-

class Solution {
public:
    int maxLength = 0;

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0, true);  // Start by going left
        dfs(root, 0, false); // Start by going right
        return maxLength;
    }

private:
    void dfs(TreeNode* node, int length, bool isLeft) {
        if (!node) return;

        // Update the maximum length if the current length is greater
        maxLength = std::max(maxLength, length);

        if (isLeft) {
            // If the current direction is left, continue to the left with a reset length, and go right increasing the length
            dfs(node->left, 1, true);   // Start a new ZigZag by going left
            dfs(node->right, length + 1, false);  // Continue the ZigZag by going right
        } else {
            // If the current direction is right, continue to the right with a reset length, and go left increasing the length
            dfs(node->right, 1, false); // Start a new ZigZag by going right
            dfs(node->left, length + 1, true);   // Continue the ZigZag by going left
        }
    }
};
