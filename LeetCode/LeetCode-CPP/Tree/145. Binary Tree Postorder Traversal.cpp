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
    
    void dfs(TreeNode* root, vector<int>& res) {
        if(root == NULL)
            return;
        dfs(root->left, res);
        dfs(root->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        dfs(root, res);
        return res;
    }
};
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            if(curr->right != NULL && curr->right != lastVisited) { // 访问右边，并且确保右边刚才没有访问过，若干右边有节点，后序遍历中右边的直接接节点必然是当前节点的前一个所进行访问的
                curr = curr->right;
            } else { // 若右边子树为空，有两种情况：1：叶子节点，访问删除即可；2：有左子树，但是后序遍历中左子树先访问的，所以依然访问当前节点并删除即可。
                res.push_back(curr->val);
                s.pop();
                lastVisited = curr;
                curr = NULL;
            }
        }
        return res;
    }
};