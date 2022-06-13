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
     int max(vector<int>& nums,int low,int high)
    {
        int m=nums[low];
        int index;
        for(int i=low+1;i<=high;i++)
        {
            if(nums[i]>m)
            {
                m=nums[i];
                index=i;
            }
        }
        
        return index;
    }
    TreeNode* bt(vector<int>& nums,int low,int high)
    {
        if(low>high)
            return NULL;
        int mid=max(nums,low,high);
        TreeNode* root=new TreeNode;
        root->val=nums[mid];
        root->left=bt(nums,low,mid-1);
        root->right=bt(nums,mid+1,high);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            if(nums.size()==NULL)
                return NULL;
        int l=0,h=nums.size()-1;
        
           return  bt(nums,l,h);
    }

};