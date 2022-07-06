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
    int rootSum(TreeNode* root, long long sum) {
        if (root ==NULL)
            return 0;
        int count = (sum == (long long)root->val) ? 1 : 0;
        return count + rootSum(root->left, sum - root->val) + rootSum(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (root ==NULL)
        return 0;
        
        return rootSum(root, (long long)sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};