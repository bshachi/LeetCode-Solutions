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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *ptr = head, *temp;
        while (ptr->next) {
            if (ptr->val == ptr->next->val) {
                temp = ptr->next;
                ptr->next = temp->next;
                delete(temp);
            }
            else ptr = ptr->next;
        }
        return head;
    }
};