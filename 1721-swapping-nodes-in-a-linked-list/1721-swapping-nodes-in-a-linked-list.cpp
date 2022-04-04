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
        
        ListNode*temp =head;
        int c=0;
        
        while(temp!=NULL)
        {
            temp=temp->next;
            c++;
            
        }
        
       int x=c-k+1,d=0,e=0;
        ListNode* swap2=head;
        ListNode* swap1=head;
        while(d<x-1)
        {
         
            swap1=swap1->next;
            d++;
            
        }
             while(e<k-1)
        {
          
            swap2=swap2->next;
                 e++;
      
        }
        
        
        int q=swap1->val;
        swap1->val=swap2->val;
        swap2->val=q;
        
        return head;
    }
};