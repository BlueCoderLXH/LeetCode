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
    // 求深度
	int GetDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		int l, r;
		l = r = 1;

		l += GetDepth(root->left);
		r += GetDepth(root->right);

		return l > r ? l : r;
	}

    bool isBalanced(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}

		int lDepth = 0, rDepth = 0;
		
		// 左子树深度
		lDepth = GetDepth(root->left);
		// 右子树深度
		rDepth = GetDepth(root->right);

		bool flag = fabs(lDepth - rDepth * 1.0f) <= 1;
        
        // 根节点, 左子树, 右子树均平衡才能算平衡二叉树
		return flag && isBalanced(root->left) && isBalanced(root->right);
    }
};
