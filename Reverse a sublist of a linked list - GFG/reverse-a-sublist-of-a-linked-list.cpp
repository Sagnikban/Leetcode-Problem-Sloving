// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
       Node* reverseNNodesFromStart(Node* head, int n){
       if(!head) return head;
       
       Node* prev = nullptr, *curr = head;
       int cnt = 0;
       
       // basic reverse a linked list code.
       while(cnt < n and curr){
           Node* tmp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = tmp;
           cnt++;
       }
       
       // after reversing our start is null and curr is at end of next
       head->next = curr;
       
       // prev becomes new head
       return prev;
   }
   
   Node* reverseBetween(Node* head, int m, int n)
   {
       // adding dummy node for clean code
       Node* dummy = new Node(-1);
       dummy->next = head;
       head = dummy;
       
       // Code begins from here
       int cnt = 0;
       Node* start = head, *prev = nullptr;
       
       // traversing till the start point
       while(cnt < m){
           cnt++;
           prev = start;
           start = start->next;
       }
       
       // this function will reverse the node total node between m and n
       // from start.
       prev->next = reverseNNodesFromStart(start, n - m + 1);
       
       // remove dummy node and return next node of dummy node
       return head->next;
   }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends