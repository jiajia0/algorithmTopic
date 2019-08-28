struct TreeNode
{
    int                    val;
    TreeNode*        left;
    TreeNode*        right;
};

__declspec( dllexport ) TreeNode* CreateTreeNode(int value);
__declspec( dllexport ) void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight);
__declspec( dllexport ) void PrintTreeNode(const TreeNode* pNode);
__declspec( dllexport ) void PrintTree(const TreeNode* pRoot);
__declspec( dllexport ) void DestroyTree(TreeNode* pRoot);
