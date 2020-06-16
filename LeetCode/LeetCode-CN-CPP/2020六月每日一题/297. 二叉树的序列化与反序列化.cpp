/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string serialized = "[";
        queue<TreeNode*> q; // 声明一个队列，用来广度优先遍历
        q.push(root);
        
        while(!q.empty()) { // 队列不为空
            TreeNode* node = q.front(); // 取出队列中的第一个元素
            q.pop();
            if(node == NULL) {
                serialized += "null";
                if(q.size() != 0) { // 右节点肯定是最后一个为空的，所以判断是否需要添加最后的一个“，”
                    serialized += ","; 
                }
                continue;
            } 

            serialized += to_string(node->val) + ","; // 序列化
            //cout << node->val << ":" << serialized << " ";
            if(node->left != NULL) {
                q.push(node->left);
            } else {
                q.push(NULL);
            }
            
            if(node->right != NULL) {
                q.push(node->right);
            } else {
                q.push(NULL);
            }
        }
        
        return serialized + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") {
            return NULL;
        }
        // 删除”【】“
        data.erase(data.begin());
        data.erase(data.end() - 1);
        
        queue<TreeNode*> q;
        vector<string> tree_data;
        split(data, tree_data, ","); // 进行分割
        TreeNode* root = new TreeNode(stoi(tree_data[0]));
        q.push(root);
        for(int i = 1 ; i < tree_data.size();) {
            int q_size = q.size(); // 记录下队列中的元素个数
            while(q_size != 0) { // 将本层的所有元素出队列，然后下一层入队列
                TreeNode* node = q.front(); // 出队列一个元素
                q.pop();
                // 先左后右
                if(tree_data[i] != "null") { // 下一层左边
                    TreeNode* next_left = new TreeNode(stoi(tree_data[i])); // 提取出当前节点的数值，并且向后移动一位
                    node->left = next_left;
                    q.push(next_left);
                }
                i++;
                if(tree_data[i] != "null") { // 下一层左边
                    TreeNode* next_right = new TreeNode(stoi(tree_data[i]));
                    node->right = next_right;
                    q.push(next_right);
                }
                i++;
                q_size--;
            }
        }
        return root;
    }

    void split(const std::string& s, std::vector<std::string>& v, const std::string& c) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));