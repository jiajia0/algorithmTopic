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
    
    // 中序遍历得到中序遍历的结果
    void dfs(TreeNode* root, vector<int>& nums) {
        if(root==NULL)
            return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        TreeNode* p = res;
        vector<int> nums;
        dfs(root, nums);
        for(int n : nums) {
            p->right = new TreeNode(n);
            p = p->right;
        }
        return res->right;
    }
};
*/

class Solution {
public:
    TreeNode* cur;
    // 边遍历边构造数
    void dfs(TreeNode* root) {
        if(root == NULL)
            return;
        dfs(root->left);
        // 遍历到中序的时候进行处理
        root->left = NULL;
        cur->right = root;
        cur = root;
        dfs(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        cur = res;
        dfs(root);
        return res->right;
    }
};