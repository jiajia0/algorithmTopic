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
    
    void dfs(TreeNode* parent, TreeNode* cur, int flag) {
        if(cur == NULL) {
            return;    
        }

        dfs(cur, cur->left, 0);
        dfs(cur, cur->right, 1);
        
        if(cur->left==NULL && cur->right==NULL&&cur->val == 0) {
            if(flag)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return root;
        dfs(root, root->left, 0);
        dfs(root, root->right, 1);
        return root;
    }
};
*/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // 检查的语句不能放在前面，因为可能向下检测完之后，当前节点符合条件，若放在上面则无法检测到
        if(root->left==NULL && root->right==NULL && root->val==0)
            return NULL;
        return root;
    }
};