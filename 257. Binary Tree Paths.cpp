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
private:
    vector<string> _mPaths;

public:
    // 先序深度遍历
    void preOrder(TreeNode* node, string path) {
        if(node != NULL)
        {
            if(node->left == NULL && node->right == NULL)
            {
                path.append(to_string(node->val));
                
                // 搜索到叶子节点, 即得到一条路径
                _mPaths.push_back(path);
            }
            else
            {
               path.append(to_string(node->val) + "->"); 
            }
            
            preOrder(node->left, path);
            preOrder(node->right, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        preOrder(root, "");
        
        return _mPaths;
    }
};
