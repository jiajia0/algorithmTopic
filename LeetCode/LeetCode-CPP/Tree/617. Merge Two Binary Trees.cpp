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

    void merge(TreeNode* root, TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL)
            return;
        if(t1 != NULL && t2 != NULL) {
            root->val = t1->val + t2->val;
        } else {
            root->val = t1!=NULL?t1->val:t2->val;
        }
        // 只要两个树其中有一个还有left节点，就继续遍历下去
        if((t1!=NULL&&t1->left!=NULL) || (t2!=NULL&&t2->left!=NULL)) {
            TreeNode* node = new TreeNode(0);
            root->left = node;
            merge(root->left, t1!=NULL?t1->left:NULL,t2!=NULL?t2->left:NULL);
        }
        if((t1!=NULL&&t1->right!=NULL) || (t2!=NULL&&t2->right!=NULL)) {
            TreeNode* node = new TreeNode(0);
            root->right = node;
            merge(root->right, t1!=NULL?t1->right:NULL,t2!=NULL?t2->right:NULL);
        }
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL)
            return t1;
        TreeNode* root = new TreeNode(0);
        merge(root, t1, t2);
        return root;
    }
};*/

/*class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        stack<vector<TreeNode*>> s;
        s.push({t1, t2});
        while(!s.empty()) {
            vector<TreeNode*> nodes = s.top();
            s.pop();
            // 若遇到空的则直接跳过，因为此时nodes[0]的right或者left必然有节点或者两个树都为空
            if(nodes[0] == NULL || nodes[1] == NULL) {
                continue;
            }
            nodes[0]->val += nodes[1]->val;
            if(nodes[0]->left == NULL) {
                nodes[0]->left = nodes[1]->left;
            } else {
                s.push({nodes[0]->left, nodes[1]->left});
            }
            if(nodes[0]->right == NULL) {
                nodes[0]->right = nodes[1]->right;
            } else {
                s.push({nodes[0]->right, nodes[1]->right});
            }
        }
        return t1;
    }
};
