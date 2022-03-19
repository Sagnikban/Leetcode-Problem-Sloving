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
        if(head->next==NULL)
        return NULL;    
        
        int c=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }    
        
        int j=c-n;
        
        if(j==0)
        {
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete(temp);
            return head;
        }
        
        temp=head;
        ListNode* prev=NULL;
        c=0;
        
        while(c<j)
        {
          
            prev=temp;
            temp=temp->next;
            c++;
        }
        
        prev->next=temp->next;
        temp->next=NULL;
        delete(temp);
        
        return head;
    }
};