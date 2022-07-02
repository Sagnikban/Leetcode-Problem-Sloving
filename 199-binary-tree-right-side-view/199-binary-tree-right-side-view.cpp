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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        {
            vector<int>t;
            return t;
            
        }   
        queue<TreeNode*>q;
        int lvl=0;
        q.push(root);
        vector<int>v;
        while(!q.empty())
        {
                
            int n=q.size();  
    
           for(int i = 1; i <= n; i++)
           {
            TreeNode* temp = q.front();
            q.pop();

            if (i == n)
            {
                v.push_back(temp->val);
            }
            
             
            if (temp->left != NULL)
            q.push(temp->left);
 
            if (temp->right != NULL)
            q.push(temp->right);
          }
        }
        return v;
    }
};