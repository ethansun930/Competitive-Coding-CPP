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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        // if (head -> next == nullptr) {
        //     return head;
        // }
        ListNode* ans = new ListNode(0);
        while (head != nullptr) {
            ListNode* dummy = ans->next;
            ans->next = new ListNode(head->val);
            ans->next->next = dummy;
            head = head->next;
        }
        return ans->next;
    }
};