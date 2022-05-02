/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Symmetric(TreeNode* left,TreeNode* right)
    {
        if(left==NULL || right==NULL)
        return left==right;
        
        if(left->val!=right->val)
        return false;
        
        return Symmetric(left->right,right->left)&& Symmetric(left->left,right->right);
            
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        
         return Symmetric(root->left,root->right);
    }
};