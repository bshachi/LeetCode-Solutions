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
    ListNode* swapPairs(ListNode* head) {
        if (not(head && head->next)) return head;
        ListNode *temp, *prev, *ptr = head;

        head = ptr->next;
        ptr->next = ptr->next->next;
        head->next = ptr;
        prev = ptr;
        ptr = ptr->next;

        while (ptr && ptr->next) {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            temp->next = ptr;
            prev->next = temp;
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};