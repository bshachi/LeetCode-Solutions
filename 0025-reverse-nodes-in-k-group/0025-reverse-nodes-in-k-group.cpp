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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *f = head, *l, *t;
        if (k == 1) return head;

        for (int i = 1; i < k; i++) {
            t = head;
            head = f->next;
            f->next = f->next->next;
            head->next = t;
        }


        while (true) {
            if (f->next == NULL) return head;
            l = f;
            f = l->next;
    
            for (int i = 1; i < k; i++) {
                if (f->next == NULL) {

                    f = l->next;
                    while (f->next) {
                        t = l->next;
                        l->next = f->next;
                        f->next = f->next->next;
                        l->next->next = t;
                    }
                    return head;
                }

                t = l->next;
                l->next = f->next;
                f->next = f->next->next;
                l->next->next = t;
            }
        }
        return head;
    }

};