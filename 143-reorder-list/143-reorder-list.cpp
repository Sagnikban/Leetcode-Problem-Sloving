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
       
         ListNode* slow=head,*fast=head->next;
        //to find midpoint of list
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* second=slow->next;
        ListNode* prev=NULL;
        slow->next=NULL;
        
        //reverse second half
        while(second){
            ListNode* tmp=second->next;
            second->next=prev;
            prev=second;
            second=tmp;
        }
        //merge two halfs
        ListNode* first=head;
        ListNode* last=prev;
        while(last){
            ListNode* t1=first->next;
            ListNode* t2=last->next;
            first->next=last;
            last->next=t1;
            first=t1,last=t2;
        }

        
    }
};