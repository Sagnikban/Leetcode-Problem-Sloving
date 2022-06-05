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
    int idx = 1;
    long int value;
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int idx_cnt = 1;
        value = root->val;
        while(!q.empty())
        {
            long int tmp = 0;
            int sz = q.size();
            idx_cnt++;
            for(int i = 0; i < sz; i++)
            {
                TreeNode* ptr = q.front();
                q.pop();
                if(ptr->left)
                {
                    tmp += ptr->left->val;
                    q.push(ptr->left);
                }
                if(ptr->right)
                {
                    tmp += ptr->right->val;
                    q.push(ptr->right);
                }
            }
            if(tmp > value && !q.empty())
            {
                idx = idx_cnt;
                value = tmp;
            }
        }
        return idx;
    }
};