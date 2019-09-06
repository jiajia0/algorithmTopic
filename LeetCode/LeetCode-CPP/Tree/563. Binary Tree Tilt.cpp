/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 这个题是需要计算出每个节点的tilt ，然后把所有节点的tilt进行相加
class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = 0, right = 0;
        left += dfs(root->left);
        right += dfs(root->right);
        res += abs(left - right); // 进行tilt的累加 
        return left + right + root->val; // 返回子节点的sum
    }
    
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return res;
    }
};
