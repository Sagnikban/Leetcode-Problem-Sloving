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
    int ans;
    int dfs(TreeNode* node)
    {
        if (node == NULL)
        return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        ans+= abs(L) + abs(R);
        return node->val + L + R - 1;
        
    }
    int distributeCoins(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};