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
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        // 叶子节点高度默认为1
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        // 左子树高度
        int left = 1; // 非叶子结点高度至少为1
        if(root->left != NULL)
        {
            left += minDepth(root->left);
        }
        
        // 右子树高度
        int right = 1; // 非叶子结点高度至少为1
        if(root->right != NULL)
        {
            right += minDepth(root->right);
        }
        
        // 左数为空, 只看右树
        if(root->left == NULL)
        {
            return right;
        }
        
        // 右树为空, 只看左树
        if(root->right == NULL)
        {
            return left;
        }
        
        // 左右子树都非空, 返回高度较小的
        return left < right ? left : right;
    }
};
