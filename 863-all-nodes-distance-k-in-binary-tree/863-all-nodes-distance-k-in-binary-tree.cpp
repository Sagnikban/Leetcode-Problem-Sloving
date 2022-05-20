/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void printAtLevel(TreeNode* root,int k,vector<int>& res)
{
    if(root==NULL)
    return;
    
    if(k==0)
    {
       res.push_back(root->val);
        return;
    }
    printAtLevel(root->left,k-1,res);
    printAtLevel(root->right,k-1,res);
    return;
    
}
int helper(TreeNode* root, TreeNode* target, int k,vector<int>& res)
{
    if(root==NULL)
    return -1;    
    
       if(root==target)
        {
            printAtLevel(root,k,res);
            return 0;
        }
        int DL =helper(root->left,target,k,res);
        
        if(DL!=-1)
        {
            if(DL+1==k)
            {
                res.push_back(root->val);
            }
            else
            {
                 printAtLevel(root->right, k-2-DL,res);
            }
            
            return 1+DL;
        }
        
        int DR =helper(root->right,target,k,res);
        
        if(DR!=-1)
        {
            if(DR+1==k)
            {
                res.push_back(root->val);
            }
            else
            {
                 printAtLevel( root->left, k-2-DR,res);
            }
            
            return 1+DR;
        }
        
        return -1; 
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
         if(root==NULL)
         return res; 
        
        if(root->left==NULL && root->right==NULL && k>0)
        return res;
        
        helper(root,target,k,res);
        return res;
       
    }
};