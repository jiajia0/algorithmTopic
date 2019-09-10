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
    
    int maxDepth(Node* root) {
        int res = 0;
        queue<Node*> q;
        if(root == NULL)
            return 0;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                for(Node* n : node->children)
                    q.push(n);
            }
            res++;
        }
        return res;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        int deep = 0;
        for(Node*node : root->children)
            deep = max(deep, maxDepth(node));
        return deep + 1;
    }
};