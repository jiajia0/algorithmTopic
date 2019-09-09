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
    
    void dfs(Node* root, vector<int>& res) {
        if(root == NULL)
            return;
        res.push_back(root->val);
        for(int i = 0; i<root->children.size(); i++) {
            dfs(root->children[i], res);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};

*/

class Solution {
public:
    // bfs 
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> res;
        if(root == NULL)
            return res;
        s.push(root);
        while(!s.empty()) {
            Node* n = s.top();
            s.pop();
            res.push_back(n->val);
            for(int i = n->children.size() -  1; i>=0;i--) {
                s.push(n->children[i]);
            }
        }
        return res;
    }
};