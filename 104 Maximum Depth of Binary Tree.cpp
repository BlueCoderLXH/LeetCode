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
    int maxDepth(TreeNode* root) {
        // 叶子节点深度为0
        if(root == NULL)
        {
            return 0;
        }
        
        int leftLen, rightLen;
        // 非叶子节点深度至少为1
        leftLen = rightLen = 1;
        
        // 左子树深度
        leftLen += maxDepth(root->left);
        // 右子树深度
        rightLen += maxDepth(root->right);
        
        // 返回深度较大的一个
        return leftLen > rightLen ? leftLen : rightLen;
    }
};
