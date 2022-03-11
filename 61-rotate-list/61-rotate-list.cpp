/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         
        ListNode* temp1=head;
         ListNode* ptr=head;
        
        int c=0;
        while(temp1!=NULL)
        {
            temp1=temp1->next;
            c++;
            
        }
        if(c==0)
        return NULL;   
        
        if(c==1)
        return head;
        
         k=k%c;
        cout<<c<<endl;
          ListNode* temp=head;
        
          
        for(int i=0;i<k;i++)
         {        
             while(temp->next!=NULL)
             {
                temp=temp->next;  
             }
            
            temp->next=head; 
              head = temp;
            ptr = temp;
			
		
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            
            temp -> next = NULL;
			
            temp = ptr;
         }
        
        return head;
    }
};