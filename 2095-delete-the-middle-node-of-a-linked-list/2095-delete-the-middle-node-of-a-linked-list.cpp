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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr =head;
        ListNode* prev=NULL;
        
        int n=0;
        while(curr!=NULL)
        {
            curr=curr->next;
            n++;
        }
        if(n==1)
        return prev;    
        int x=floor(n*1.0/2);
         n=0;
        curr=head;
        while(n<x)
        {
            
            prev=curr;
            curr=curr->next;
            n++;
                
        
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
        return head;
    }
};