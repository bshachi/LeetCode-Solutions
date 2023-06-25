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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            n++;
        }
        if (n == 1) return NULL;

        n /= 2;
        p = head;

        while (--n) {
            p = p->next;
        }

        p->next = p->next->next;
        return head;
    }
};