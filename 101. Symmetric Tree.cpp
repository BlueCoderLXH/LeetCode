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
    bool judgeLeftAndRight(TreeNode* left, TreeNode* right) {
        // 左子树和右子树都为空
        if(left == NULL && right == NULL)
        {
            return true;
        }
        // 左子树, 右子树其中一个为空
        else if(left == NULL || right == NULL)
        {
            return false;
        }
        
        // 左/右子树非空, 但val值不等
        if(left->val != right->val)
        {
            return false;
        }
        
        // 依次判断左孩子的左子树是否等于右孩子的右子树, 右孩子的左子树是否等于左孩子的右子树
        return judgeLeftAndRight(left->left, right->right) &&
        judgeLeftAndRight(left->right, right->left);
    }
    
    // 依次判断root的左子树与右子树是否相等
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        
        return judgeLeftAndRight(root->left, root->right);
    }
};
