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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            c++;
        }
        if(c==1)
        return NULL;    
        
        int x=c-n+1;
        
        if(x==1)
        {
         ListNode * d=head;
         head=head->next;
         delete d;
          return head; 
        }
      
        int d=0;
        temp=head;
        while(temp)
        {
            d++;
            if(d+1==x)
            {
             
              ListNode* y=temp->next;
              temp->next=temp->next->next;
                delete y;
            }
            temp=temp->next;
        }
        
        return head;
    }
};