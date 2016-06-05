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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack; // 用以一个栈保存先序遍历节点
        vector<int> preorder;
        
        if(root == NULL)
        {
            return preorder;
        }
        
        nodeStack.push(root); // 根节点压栈
        
        while(!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();
            
            preorder.push_back(node->val); // 遍历当前子树的根节点
            nodeStack.pop();               // 栈顶节点出栈
            
            if(node->right != NULL)    // 先压右子树(因为栈是先进后出, 保证左子树先于右子树遍历)
            {
                nodeStack.push(node->right);
            }
            
            if(node->left != NULL)     // 后压左子树
            {
                nodeStack.push(node->left);
            }
        }
        
        return preorder;
    }
};
