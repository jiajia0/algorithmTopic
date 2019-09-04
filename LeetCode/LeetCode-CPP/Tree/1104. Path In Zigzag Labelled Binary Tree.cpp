// 本题的主要关键点就是计算镜像二叉树对应位置上的序号
// k层二叉树，计算出总共的节点，然后得到对应位置右边剩余的节点，然后加上之前的节点
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int k = log(label)/log(2) + 1; // 算出label对应的树的层次是多少
        // 2^k-1 ：整个树一共的节点个数，减去label得到的结果为：在第k层，label右边还有多少个节点。
        // 然后右边剩余的节点，加上上一层的节点个数，就是镜像二叉树label对应位置的节点数
        int mirror_label = pow(2,k) - 1 - label + pow(2,k-1); // 算出镜像的二叉树此时对应的数字是多少
        bool is_mirror = false;
        // 当二叉树达到一层的时候结束
        while(mirror_label != 0 && label != 0) {
            if(is_mirror) {
                res.insert(res.begin(), mirror_label);
            } else {
                res.insert(res.begin(), label);
            }
            is_mirror = !is_mirror;
            label /= 2;
            mirror_label /= 2;
        }
        return res;
    }
};