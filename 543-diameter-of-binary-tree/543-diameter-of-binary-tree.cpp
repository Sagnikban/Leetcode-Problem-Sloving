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
    int maxi=0;
    int helper(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        
        //left subtree call
        int lh =helper(root->left);
        
        //right subtree call
        int rh=helper(root->right);
        
        //for each node we are checking the sum of the 
        //heights of left subtree and right subtree
        
        maxi=max(maxi,lh+rh);
        
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        
         helper(root);
         return maxi;
        

    }
};