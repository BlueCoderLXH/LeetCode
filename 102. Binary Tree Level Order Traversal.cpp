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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue; // 辅助队列
        vector<vector<int>> results;
        
        // 根结点为空
        if(root == NULL)
        {
            return results;
        }
        
        nodeQueue.push(root); // 一开始根结点入队
        
        while(!nodeQueue.empty())
        {
            vector<int> level;
            
            queue<TreeNode*> tmpQueue; // 临时队列(关键)
            nodeQueue.swap(tmpQueue);  // nodeQueue的结点交换到tmpQueue中
            
            /// 加入层序列结点的中的孩子节点(一层一层的遍历)
            while(!tmpQueue.empty())
            {
                TreeNode* node = tmpQueue.front();
                
                // 加入层序列结点
                level.push_back(node->val);
                
                if(node->left != NULL)
                {
                   nodeQueue.push(node->left); 
                }
                
                if(node->right != NULL)
                {
                   nodeQueue.push(node->right); 
                }
                
                tmpQueue.pop();
            }
            
            results.push_back(level);
        }
        
        return results;
    }
};
