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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        head = head->next;

        delete(temp);
        ListNode* ptr = head;

        while (ptr) {
            while (ptr->next->val != 0) {
                ptr->val += ptr->next->val;
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete(temp);
            }
            temp = ptr->next;
            ptr->next = ptr->next->next;
            delete(temp);
            ptr = ptr->next;
        }

        return head;
    }
};