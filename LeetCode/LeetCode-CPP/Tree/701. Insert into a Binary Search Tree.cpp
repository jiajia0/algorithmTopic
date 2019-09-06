/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 自定向下
/*
class Solution {
public:
    
    void dfs(TreeNode* root, int val) {
        if(root == NULL)
            return;
        // 找到叶子节点，把新节点插入到叶子节点下面
        if(root->left == NULL && root->val > val) {
            TreeNode* node = new TreeNode(val);
            root->left = node;
        }
        if(root->right == NULL && root->val < val) {
            TreeNode* node = new TreeNode(val);
            root->right = node;
        }
        if(root->val < val)
            dfs(root->right, val);
        if(root->val > val)
            dfs(root->left, val);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        dfs(root, val);
        return root;
    }
};
*/
// 自底向上
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }
        if(root->val < val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};