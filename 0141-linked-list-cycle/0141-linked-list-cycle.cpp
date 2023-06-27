/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        for (int i = 0; i < 10001; i++) {
            if (ptr == NULL) return false;
            ptr = ptr->next;
        }
        return true;
    }
};