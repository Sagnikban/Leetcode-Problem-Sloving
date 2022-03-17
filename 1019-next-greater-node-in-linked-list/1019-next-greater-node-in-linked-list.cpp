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
       
        ListNode* curr = head; 
        vector<int>a;
         while(curr!=NULL){      
             a.push_back(curr->val);      
             curr = curr->next;
         }
        
        int n = a.size();        
        stack<int> s;
    vector<int>res(n);
    for (int i = n - 1; i >= 0; i--) {
       
        if (!s.empty()) {
            while (!s.empty() && s.top() <= a[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? 0 : s.top();
        s.push(a[i]);
    }
     
      return res; 
    }
};