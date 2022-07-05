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
class FindElements {
public:
    TreeNode* node;
    void recover(TreeNode* root,int x)
    {
        if(root->right==NULL && root->left==NULL)
        return;
        
        if(root->left!=NULL)
        {
        if(root->val==x && root->left->val==-1)
        {
            root->left->val=2*x+1;
    
             recover(root->left,root->left->val);
        }  
        }
        
        if(root->right!=NULL)
        {
        if(root->val==x && root->right->val==-1)
        {
            root->right->val=2*x+2;
             recover(root->right,root->right->val);
        }  
      }
        
    }
    

    
    FindElements(TreeNode* root) {
        node=root;   
        
       
        node->val=0;
     
        recover(node,node->val);
    }
    
    bool search(TreeNode* node,int target)
    {
        if(node==NULL)
        return false;    
          
        if(node->val!=target && node->left==NULL &&node->right==NULL)
        return false;
        
        if(node->val==target)
        return true;
        
        return search(node->left,target)||search(node->right,target);
    }
    
    bool find(int target) {
        return search(node,target);
      
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */