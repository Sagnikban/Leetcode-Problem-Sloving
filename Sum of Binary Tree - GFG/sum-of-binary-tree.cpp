// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* make_tree()
{
	int n;
	cin>>n;
    
	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-=2 )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}
		
		
		cin>> a >> b >> c;
		
		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

long int sumBT(Node* root);


int main()
{
    int t;cin>>t;while(t--){
    	
    	Node* head = make_tree();
    
        cout<<sumBT(head)<<endl;
    }
	return 1;
}
// } Driver Code Ends


/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// Function should return the sum of all the elements
// of the binary tree


void inorder(Node* root,vector<int>&ans){
   if(root==NULL){
       return;
   }
   inorder(root->left,ans);
   ans.push_back(root->key);
   inorder(root->right,ans);
}

 

long int sumBT(Node* root)

{

  vector<int>ans;

  inorder(root,ans);

  

  long sum=0;

  for(int i=0;i<ans.size();i++){

      sum+=ans[i];

  }

  

  return sum;
  }