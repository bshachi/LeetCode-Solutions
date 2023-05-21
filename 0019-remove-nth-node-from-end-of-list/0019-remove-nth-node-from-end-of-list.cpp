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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* traversal = head;
        vector<ListNode*> list;

        while (traversal != NULL) {
            list.push_back(traversal);
            traversal = traversal->next;
        }

        int s = list.size();
        if (s == n) return head->next;
        list[s - n - 1]->next = list[s - n - 1]->next->next;

        return head; 
    }
};