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
    
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_max = maxDepth(root->left) + 1;
        int right_max = maxDepth(root->right) + 1;
        return max(left_max, right_max);
    }
};
*/

class Solution {
 public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size(); // 记录当前层有多少个节点
            
            for(int i = 0; i < n; i ++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res++;
        }
        return res;
    }
};