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
    TreeNode* res = NULL;
    void dfs(TreeNode* root, int val) {
        if(root == NULL)
            return;
        if(root->val == val)
            res = root;
        dfs(root->left, val);
        dfs(root->right, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        dfs(root, val);
        return res;
    }
};
*/

class Solution {
public:
        TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == val) {
                return node;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return res;
    }
};
