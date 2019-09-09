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
            return ;
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
*/

class Solution {
public:
      vector<int> inorderTraversal(TreeNode* root) {
          vector<int> res;
          if(root == NULL)
              return res;
          stack<TreeNode*> s;
          TreeNode* curr = root; // 这里并不先放入root节点
          while(curr != NULL || !s.empty()) {
              while(curr != NULL) { // 检查左子树
                  s.push(curr);
                  curr = curr->left;
              }
              curr = s.top();
              s.pop();
              res.push_back(curr->val);
              curr = curr->right; // 再检查右子树
          }
          return res;
      }
};