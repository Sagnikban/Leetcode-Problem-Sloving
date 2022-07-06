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
  
        int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int index = 0, ans =0;
            
            while(curr != NULL)
            {
            curr=curr->next;
            index++;
            
        }
        curr=head;
        while(curr != NULL){
            if(curr->val != 0){
                ans += pow(2, index-1);
            }
            index--;
            curr=curr->next;
        }
        return ans;
    
    }
};