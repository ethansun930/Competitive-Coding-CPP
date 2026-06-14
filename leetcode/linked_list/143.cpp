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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* back = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* front = head;
        while (back != nullptr && front != nullptr) {
            ListNode* next = front->next;
            front->next = back;
            back = back->next;
            front->next->next = next;
            front = next;
        }
    }
};