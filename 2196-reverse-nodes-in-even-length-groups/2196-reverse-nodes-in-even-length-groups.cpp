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

    void reverseOneGroup(ListNode* ptr, int n) {
        ListNode *cstart = ptr->next, *cend = ptr->next, *temp;
        ptr->next = ptr->next->next;

        for (int i = 1; i < n; i++) {
            temp = cstart;
            cstart = ptr->next;
            ptr->next = ptr->next->next;
            cstart->next = temp;
        }

        cend->next = ptr->next;
        ptr->next = cstart;
    }


    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* ptr = head;
        ListNode* checker;
        ListNode* temp;

        for (int i = 2; ptr->next != NULL; i++) {
            checker = ptr;
            temp = ptr->next;

            for (int j = 0; j < i; j++) {
                checker = checker->next;
                if (checker == NULL) {
                    if (j % 2 == 0) reverseOneGroup(ptr, j);
                    return head; 
                }
            }

            if (i % 2 == 0) {
                reverseOneGroup(ptr, i);
                ptr = temp;
            }
            else ptr = checker;
        }
        return head;
    }
};