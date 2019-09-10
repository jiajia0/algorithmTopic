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
class Solution {
public:
    
    bool dfs(TreeNode* root, int val) {
        if(root == NULL)
            return true;
        if(root->val != val)
            return false;
        return dfs(root->left, val) && dfs(root->right, val);    
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return true;
        bool res = dfs(root, root->val);
        return res;
    }
};
*/
/*
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return true;
        int val = root->val;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if(node->val != val)a
                return false;
            if(node->left)
                s.push(node->left);
            if(node->right)
                s.push(node->right);
        }
        return true;
    }
};
*/
// ×Ôµ×ÏòÉÏ
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
     bool left_val = (root->left == NULL) || (root->left->val == root->val && isUnivalTree(root->left));
     bool right_val = (root->right == NULL) || (root->right->val == root->val && isUnivalTree(root->right));
     return left_val && right_val;
    }
};