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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q == p )
            return true;
        if(q == NULL || p == NULL)
            return false;
        
        if(q->val != p->val) {
            return false;
        }
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        return left && right;
    }
};
*/

class Solution {
public:
    
    bool check(TreeNode* p, TreeNode* q) {
        if(p == q)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == q)
            return true;
        queue<TreeNode*> q1; // 存放q
        queue<TreeNode*> q2; // 存放p
        
        q1.push(q);
        q2.push(p);
        
        while(!q1.empty()) {
            q = q1.front();
            p = q2.front();
            q1.pop();
            q2.pop();
            if(!check(q, p))
                return false;
            if(!check(q->left, p->left))
                return false;
            if(q->left && p->left) { // 验证一下左右是否为空，不为空再进行添加
                q1.push(q->left);
                q2.push(p->left);
            }
            if(!check(q->right, p->right))
                return false;
            if(q->right && p->right) {
                q1.push(q->right);
                q2.push(p->right);
            }
        }
        
        return true;
    }
};