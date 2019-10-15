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
    
    void dfs(vector<string>& res, TreeNode* node, string path) {
        if(node->left == NULL && node->right == NULL) {
            path += to_string(node->val);
            res.push_back(path);
            return;
        }
        path += to_string(node->val);
        path += "->";
        if(node->left)
            dfs(res, node->left, path);
        if(node->right)
            dfs(res, node->right, path);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        
        dfs(res, root, "");
        return res;
    }
};