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
    void reorderList(ListNode* head) {
       
        if(!head || !head->next)
        return;    
       
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
       
        
        ListNode* current = slow->next;
        slow->next=NULL;
        ListNode *prev = NULL, *next = NULL;
 
        while (current) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        

        ListNode* n1 =head,*n2 =prev;
        
      
        while(n2)
        {
            
            ListNode* t1=n1->next;
            ListNode* t2=n2->next;
            
            
            n1->next=n2;
            n2->next=t1;
            n1=t1;
            n2=t2;
            
        }
        

        
    }
};