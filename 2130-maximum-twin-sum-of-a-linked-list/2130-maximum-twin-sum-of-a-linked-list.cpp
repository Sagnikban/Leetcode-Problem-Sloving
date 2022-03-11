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
	// simple iterative Reverse Linked List approach
  ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
class Solution {
public:
    int pairSum(ListNode* head) {
      // initialising two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
		// fast pointer moves two nodes at a time
		// slow pointer moves one node at a time
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
		
		// reverse the second half of the list
        slow = reverse(slow);
        
        int maxi = INT_MIN;
        
		// iterating through the two pointers from left-to-right
		// finding the max value of sum pairs
        while (slow != NULL) {
            maxi = max(maxi, head->val + slow->val);
            slow = slow->next;
            head = head->next;
        }
        
		// return the max value obtained
        return maxi;
    }
    
};
