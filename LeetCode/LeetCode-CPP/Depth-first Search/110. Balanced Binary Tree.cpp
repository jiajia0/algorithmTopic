/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
       
    int depth(TreeNode* node) {
        if(node == NULL)
            return 0;
        int leftPath = depth(node->left);
        int rightPath = depth(node->right);
        return max(leftPath, rightPath) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(right - left) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};