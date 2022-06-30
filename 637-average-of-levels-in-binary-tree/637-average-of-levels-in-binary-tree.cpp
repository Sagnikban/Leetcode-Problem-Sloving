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
    vector<double> averageOfLevels(TreeNode* root) {
       
 
    queue<TreeNode *> q;
 
   vector<double>ans;
    q.push(root);
      
    while (q.empty() == false)
    {

        int nodeCount = q.size();
        double n= nodeCount;
        double sum=0.00000;
        while (nodeCount > 0)
        {
            TreeNode* node = q.front();
            sum+=node->val;
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        ans.push_back(sum/n);
    }
        return ans;
    }
};