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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            res++;
            while(n--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left==NULL && node->right==NULL) //遇到叶子节点直接return
                    return res;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) // 空节点不进行计算
            return 0;
        // 这道题是root到leaf的最下距离，所以一定要到叶子节点
        if(root->left == NULL && root->right == NULL) // 叶子节点计算一个
            return 1;
        // 若二叉树只有一边有子树，则到叶子节点的最小深度应该是这个子树的，将空的另一边设置为MAX，则通过min计算可得到不空子树的深度
        // 避免将空的一遍计算成0 ， 一边子树为空，一边不为空，则不满足到leaf的条件，所以需要继续向下寻找
        int left_min = root->left ? minDepth(root->left) : INT_MAX;
        int right_min = root->right ? minDepth(root->right) : INT_MAX;
        return min(left_min, right_min) + 1;
    }
};