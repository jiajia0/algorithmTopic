/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    
    void getOrderTraversal(int deep, TreeNode* root , vector<vector<int>>& res) {
        if(root == NULL)
            return;
        if(deep == res.size()) {
            res.push_back(vector<int>());
        }
        res[deep].push_back(root->val);
        getOrderTraversal(deep+1, root->left, res);
        getOrderTraversal(deep+1, root->right, res);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        getOrderTraversal(0, root, res);
        reverse(res.begin(), res.end());
        return res;
    }
};*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            vector<int> tmp;
            TreeNode* ntmp;
            int n = s.size();
            for(int i = 0; i < n;i++) {
                ntmp = s.front();
                s.pop();
                tmp.push_back(ntmp->val);
                if(ntmp->left)
                    s.push(ntmp->left);
                if(ntmp->right)
                    s.push(ntmp->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};
    