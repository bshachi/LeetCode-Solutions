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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* ptr = new ListNode();
        ptr->next = head;
        head = ptr;

        for (int i = 1; i < left; i++) {
            ptr = ptr->next;
        }

        ListNode *cstart = ptr->next, *cend = ptr->next, *temp;
        ptr->next = ptr->next->next;

        for (int i = left; i < right; i++) {
            temp = cstart;
            cstart = ptr->next;
            ptr->next = ptr->next->next;
            cstart->next = temp;
        }

        cend->next = ptr->next;
        ptr->next = cstart;

        temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
};