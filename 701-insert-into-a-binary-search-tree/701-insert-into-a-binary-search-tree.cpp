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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
             if(root==NULL)
            return new TreeNode(val);
        
		//if val is greater than node value, we call func on right of node
        if(root->val < val)
        {
            root->right=insertIntoBST(root->right,val);
            return root;
        }
        
		//if val is lesser than node value, we call func on left of node
        else
        {
            root->left=insertIntoBST(root->left,val);
            return root;
        }
    }
};