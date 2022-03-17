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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * temp=head;
        vector<int>ans;
        while(temp!=NULL)
        {
            ListNode*dummy=temp->next;
            int flag=1;
            while(dummy!=NULL)
            {
                if(dummy->val>temp->val)
                {
                    flag=2;
                      ans.push_back(dummy->val)   ;
                    break;
                }
                dummy=dummy->next;
               
            }
            
            
            if(flag==1)
            ans.push_back(0);  
            temp=temp->next;
        }
        
        return ans;
    }
};