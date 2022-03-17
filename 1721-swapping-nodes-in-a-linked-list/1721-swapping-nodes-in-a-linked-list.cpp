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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kth_from_front;
        ListNode* kth_from_end;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        temp=head;
        
        int c=0;
        while(temp!=NULL)
        {  c++;
           
            if(c==k)
            kth_from_front=temp;
         
            if(c==n-k+1)
            kth_from_end=temp; 
            
            temp=temp->next;
        }
        
         swap(kth_from_front->val,kth_from_end->val);
         return head;
    }
};