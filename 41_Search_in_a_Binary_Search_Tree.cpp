/*

PRoblem Statement -

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 
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
    TreeNode* findNode(TreeNode* root, int data){
        TreeNode* temp = NULL;
        if(root == NULL){
            return root;
        }
        if(data == root -> val){
            return root;
        }
        else if(data > root -> val){
            return findNode(root -> right, data);
        }
        else{
            return findNode(root -> left, data);
        }
        //return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return findNode(root , val);   
    }
};