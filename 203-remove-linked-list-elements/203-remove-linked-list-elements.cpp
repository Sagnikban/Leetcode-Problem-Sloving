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
    ListNode* removeElements(ListNode* head, int val) {
       
        if(head==NULL)
        return head;
        
        ListNode* temp=head;
        while(head->val==val && head!=NULL)
        {
            ListNode* t=head;
            head=head->next;
            delete t;
            
            if(head==NULL)
            return NULL;    
        }
        temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
         
            if(temp->val==val)
            {
                ListNode* del=temp;
                
                prev->next=temp->next;
                temp=temp->next;
                delete del;
            }
            else
            {
                
            prev=temp;
            temp=temp->next;
        
            }
            
            if(temp==NULL)
            return head;    
        }
    
        return head;
    }
};