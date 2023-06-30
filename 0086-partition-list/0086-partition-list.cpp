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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p1 = NULL, *p2 = NULL, *i1 = NULL, *i2 = NULL;
        
        while (head) {
            if (head->val < x) {
                if (p1) {
                    i1->next = head;
                    i1 = i1->next;
                }
                else {
                    p1 = head;
                    i1 = p1;
                }
            }
            else {
                if (p2) {
                    i2->next = head;
                    i2 = i2->next;
                }
                else {
                    p2 = head;
                    i2 = p2;
                }
            }

            head = head->next;
            if (i1) i1->next = NULL;
            if (i2) i2->next = NULL;
        }
        if (p1 == NULL) return p2;
        if (p2 == NULL) return p1;
        i1->next = p2;
        return p1;
    }
};