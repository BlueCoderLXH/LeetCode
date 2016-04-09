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
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL)
        {
            // 先交换左子树
            invertTree(root->left);
            // 再交换右子树
            invertTree(root->right);
            
            // 交换左右子树
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        
        return root;
    }
};
