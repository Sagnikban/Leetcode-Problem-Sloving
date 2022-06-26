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
      vector<int>v;
    bool findTarget(TreeNode* root, int k) {
       
        inorder(root);
        int n=v.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if((v[i]+v[j])==k)
            {
                return true;
            }
            else if((v[i]+v[j])<k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
        
        
    }
void inorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
    
}
};