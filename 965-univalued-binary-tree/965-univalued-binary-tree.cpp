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
    
    
    void helper(TreeNode* root,int& x, bool& flag)
    {   
    
        if(root==NULL)
        return;
        
        helper(root->left,x,flag);
        if(x!=root->val)
        {
         flag=false;
         return;
        }

        helper(root->right,x,flag);
    }
    bool isUnivalTree(TreeNode* root) {
        
        int x=root->val;
        bool flag=true;
        helper(root,x,flag);
        
        return flag;
        
    }
};