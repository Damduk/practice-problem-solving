/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int res = 0;
int height(TreeNode* node) {    
    int lh = 0;
    if (node->left != NULL)
        lh = 1 + height(node->left);
    
    int rh = 0;
    if (node->right != NULL)
        rh = 1 + height(node->right);
    
    res = max(res, lh + rh);

    return max(lh, rh);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        if (root == NULL)
            return res;
        
        int lh = 0;
        if (root->left != NULL)
            lh = 1 + height(root->left);
            
        int rh = 0;
        if (root->right != NULL)
            rh = 1 + height(root->right);
        
        res = max(res, lh + rh);
        
        return res;
    }
};