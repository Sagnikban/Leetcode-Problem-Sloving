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
    bool isPalindrome(ListNode* head) {
         ListNode* fast = head;
        ListNode* slow = head;

        //Code to get the mid of the linkedlist
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //slow will now point towards midpoint of linkedlist


        //Code to reverse the second half of the linkedlist (starting from the mid point)
        ListNode* prev = NULL;
        ListNode* nxt;
        while (slow != NULL) {
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        //Two pointers (to check if both linked list are same)
        ListNode* j = prev;
        ListNode* i = head;
        while (j != NULL) {
            if (i->val != j->val)
                return false;
            i = i->next;
            j = j->next;

        }

        return true;
    }
};