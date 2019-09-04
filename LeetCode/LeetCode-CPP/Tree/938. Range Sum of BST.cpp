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
    // 在二叉搜索树中，返回在 L <= x <= R 区间中的节点之和
    int G_L;
    int G_R;
    
    int dfs(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        int res = 0;
        // 在L和R区间内，进行相加
        if(root->val <= G_R && root->val >= G_L) {
            res = root->val + dfs(root->left);
            res = res + dfs(root->right);
        } else if(root->val > G_R) {
            res += dfs(root->left);
        } else {
            res += dfs(root->right);
        }
        return res;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        G_L = L;
        G_R = R;
        int res = dfs(root);
        return res;
    }
};
*/

/*
class Solution {
public:
    // 在二叉搜索树中，返回在 L <= x <= R 区间中的节点之和
    int G_L;
    int G_R;
    
    int dfs(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        int res = 0;
        // 在L和R区间内，进行相加
        if(root->val <= G_R && root->val >= G_L) {
            res += root->val;
        }
        if(root->val > G_L) // 当前节点比L大，说明左边还有查找的空间
            res += dfs(root->left);
        if(root->val < G_R) // 说明右边还有查找的空间
            res += dfs(root->right);
        return res;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        G_L = L;
        G_R = R;
        int res = dfs(root);
        return res;
    }
};*/

class Solution {
public:
    // 非递归写法，借用到栈
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return 0;
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top(); // 得到栈顶的元素
            s.pop();
            if(node->val >= L && node->val <= R)
                res += node->val;
            if(node->val > L && node->left)
                s.push(node->left);
            if(node->val < R && node->right)
                s.push(node->right);
        }
        return res;
    }
};