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
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        
        int rh=findheightright(root);
        int lh=findheightleft(root);
        
        if(lh==rh)
        return pow(2,lh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int findheightleft(TreeNode* root)
    {
        int c=0;
        while(root!=NULL)
        {
            c++;
            root=root->left;
        }
        
        return c;
    }
    
      int findheightright(TreeNode* root)
    {
        int c=0;
        while(root!=NULL)
        {
            c++;
            root=root->right;
        }
        
        return c;
    }
};