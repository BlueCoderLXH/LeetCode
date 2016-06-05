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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> inorder;
        
        while(root != NULL)
        {
            nodeStack.push(root);
            root = root->left;    // 先遍历左子树
            
            /*
                1. 第一次进入while循环root为空, 表示左子树为空, 然后遍历根节点和右子树
                2. while循环执行第二次, 表明右子树也为空, 那么就要遍历上一层根节点和其右子树了
            */
            while(root == NULL && !nodeStack.empty())
            {
                root = nodeStack.top();
                nodeStack.pop();
                
                inorder.push_back(root->val); // 遍历根节点
                
                root = root->right;           // 再遍历右子树
            }
        }
        
        return inorder;
    }
};
