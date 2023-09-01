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
        head = new ListNode(5000, head);
        ListNode *ptr = head, *temp;
        int v;

        while (ptr->next && ptr->next->next) {
            if (ptr->next->val == ptr->next->next->val) {
                v = ptr->next->val;
                while (ptr->next && ptr->next->val == v) {
                    temp = ptr->next;
                    ptr->next = temp->next;
                    delete(temp);
                }
            }
            else ptr = ptr->next;
        }

        temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
};