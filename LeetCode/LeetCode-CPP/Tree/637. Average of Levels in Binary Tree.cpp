/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 使用栈进行操作
/*class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty()) {
            double sum = 0; // 记录这层所有的和
            int num = 0; // 记录这层有多少个节点
            int n = q.size();
            TreeNode* tmp;
            for(int i = 0; i < n; i++) {
                tmp = q.front();
                q.pop();
                sum += tmp->val;
                num++;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            res.push_back(sum / num);
        }
        return res;
    }
};
*/
class Solution {
public:
    
    void dfs(int deep, TreeNode* root, vector<vector<double>> &nodes) {
        if(root == NULL)
            return;
        if(deep == nodes.size()) {
            nodes.push_back(vector<double>());
        }
        nodes[deep].push_back(root->val);
        dfs(deep+1, root->left, nodes);
        dfs(deep+1, root->right, nodes);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> nodes;
        dfs(0, root, nodes);
        vector<double> res;
        for(int i = 0; i < nodes.size();i++) {
            //cout << accumulate(nodes[i].begin(), nodes[i].end(), 0.0) << endl;
            // accumulate第三个参数就是返回的类型参数
            res.push_back(accumulate(nodes[i].begin(), nodes[i].end(), 0.0) / (nodes[i].size() / 1.0));
        }
        return res;
    }
};