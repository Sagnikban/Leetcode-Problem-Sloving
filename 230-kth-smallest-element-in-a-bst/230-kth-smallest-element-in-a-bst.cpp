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
    void helper(TreeNode* root, int &k,int &ans) {
        if(!root || k == 0) return;
        helper(root->left,k,ans);
        if(k == 0) return;
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        helper(root->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        helper(root,k,ans);
        return ans;
    }
};