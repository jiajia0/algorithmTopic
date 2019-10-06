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
    unordered_map<int,int> m;
    bool res = false;
    
    void dfs(TreeNode* node, int target, int flag) {
        if(node == NULL)
            return;
        if(flag) { // flag == 1 , 遍历tree1
            m[target - node->val]++;
            dfs(node->left, target, 1);
            dfs(node->right, target, 1);
        } else {
            if(m.count(node->val) == 1) {
                res = true;
                return;
            }
            dfs(node->left, target, 0);
            dfs(node->right, target, 0);
        }
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs(root1, target, 1); // 先遍历一遍树
        dfs(root2, target, 0);
        return res;
    }
};
*/
/*
class Solution {
public:
        
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL || root2 == NULL)
            return false;
        if(binarySearch(root2, target - root1->val))
            return true;
        else
            return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target);
    }
    
    bool binarySearch(TreeNode* node, int target) {
        if(node == NULL)
            return false;
        if(node->val == target)
            return true;
        return node->val > target ? binarySearch(node->left, target) : binarySearch(node->right, target);
    }
};
*/
class Solution {
public:
        
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL || root2 == NULL)
            return false;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        TreeNode* t1,* t2;
        while(true) {
            // root1 移动到最左边
            while(root1 != NULL) { 
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2 != NULL) {
                st2.push(root2);
                root2 = root2->right;
            }
            if(st1.empty() || st2.empty())
                break;
            t1 = st1.top();
            t2 = st2.top();
            if(t1->val + t2->val == target)
                return true;
            else if(t1->val + t2->val < target) {
                st1.pop();
                root1 = t1->right;
            } else {
                st2.pop();
                root2 = t2->left;
            }
        }
        return false;
    }
};