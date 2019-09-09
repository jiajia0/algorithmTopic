/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(Node* n : node->children)
                    q.push(n);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
*/

class Solution {
public:
    
    void dfs(Node* root, int deep, vector<vector<int>>& res) {
        if(root == NULL)
            return;
        if(res.size() == deep)
            res.push_back(vector<int>());
        res[deep].push_back(root->val);
        for(Node* n : root->children) {
            dfs(n, deep+1, res);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
};