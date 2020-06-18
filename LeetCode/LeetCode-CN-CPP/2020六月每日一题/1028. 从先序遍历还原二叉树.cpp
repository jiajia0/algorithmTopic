/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 假设输入格式合法
    TreeNode* recoverFromPreorder(string S) {
        if(S.size() == 0) {
            return NULL;
        }
        int num_start_index = 0; // 当前数字的起始位置
        int num_end_index = S.find("-") ; // 当前数字的最后位置 + 1
        int cur_level = 0; // 记录当前的层次
        TreeNode* root = new TreeNode(stoi(S.substr(num_start_index, num_end_index)));
        TreeNode* p = root;
        stack<TreeNode*> stk;
        stk.push(p);
        // 即便结束时 stk也不为空
        while(!stk.empty()) {
            TreeNode* node = NULL;
            // 判断下个节点是不是下一层的
            size_t next_num_start = S.find_first_not_of("-", num_end_index); // 找到下一个非“-”的位置
            if(next_num_start == string::npos) { // 说明已经到了字符串末尾, 真正的结束条件
                return root;
            }
            size_t next_num_end = S.find("-", next_num_start); // 找到下一个“-”的位置 ， 也是下一个数字位置+1
            if(next_num_end == string::npos) { // 说明已经是最后一个数字
                next_num_end = S.size(); // 记录为字符串的长度
            }
            int next_level = next_num_start  - num_end_index; // 得到下面是第几层的
            int next_num = stoi(S.substr(next_num_start, next_num_end)); // 提取出下一个数字
            //cout << "cur_level:" << cur_level << " , next_level:" << next_level;
            //cout << "cur_num:" << p->val << " , next_num:" << next_num <<  " ,stknum:" << stk.size() <<endl;
            if(next_level > cur_level) { // 如果是当前层下面的层的话就添加到当前节点的左节点
                node = new TreeNode(next_num);
                p->left = node;
                p = node;
                //cout << "》链接左节点，链接后的值为：" << p->val << endl;
                stk.push(node);
                cur_level = next_level;
                num_start_index = next_num_start;
                num_end_index = next_num_end;
                continue;
            }

            if(next_level == cur_level) { // 如果下一层等于当前层，说明是同级别的
                stk.pop(); // 当前层节点出栈
                p = stk.top(); // 获取上一层的节点
                node = new TreeNode(next_num); 
                p->right = node;
                p = node;
                //cout << "=链接右节点，链接后的值为：" << p->val << endl;
                stk.push(node);
                cur_level = next_level;
                num_start_index = next_num_start;
                num_end_index = next_num_end;
                continue;
            }
            if(next_level < cur_level) {
                stk.pop();
                p = stk.top();
                //cout << "《此时的值为：" << p->val << endl;
                cur_level--;
            }
        }
        return root;
    }
};