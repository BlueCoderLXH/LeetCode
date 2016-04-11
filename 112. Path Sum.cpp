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
    bool hasPathSum(TreeNode* root, int sum) {
        static int pathSum = 0;
        
        // 空树
        if(root == NULL)
        {
            return false;
        }
        
        // 叶子节点
        if(root->left == NULL && root->right == NULL)
        {
            return (pathSum + root->val) == sum;
        }
        
        pathSum += root->val;
        // 左子树
        bool left = false;
        if(root->left != NULL)
        {
            left = hasPathSum(root->left, sum);
        }
        
        // 右子树
        bool right = false;
        if(root->right != NULL)
        {
            right = hasPathSum(root->right, sum);
        }
        pathSum -= root->val;
        
        // 左右子树中有一条路径满足即可
        return left || right;
    }
};
