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
    map<int,int> mp;
    int findDepth(TreeNode* root,int val,int l){
        if(root==NULL){
            return 0;
        }
        if(root->val==val){
            return l;
        }
        return max(findDepth(root->left,val,l+1),findDepth(root->right,val,l+1));
        
    }
    void makeMap(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left&&!root->right){
            mp[root->left->val]=root->val;
            
        }
         if(!root->left&&root->right){
            mp[root->right->val]=root->val;
            
        }
        if(root->right&&root->left){
            mp[root->left->val]=root->val;
            mp[root->right->val]=root->val;
        }
        makeMap(root->left);
        makeMap(root->right);
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        int m=findDepth(root,x,0);
        int n=findDepth(root,y,0);
        makeMap(root);
    
        
        if((m==n)&&mp[x]!=mp[y]){
            return true;
        }
        else{
            return false;
        }
        
    }
};