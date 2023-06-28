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
    void insert(ListNode* ind, ListNode* node) {
        ListNode* temp = node->next;
        node->next = node->next->next;
        temp->next = ind->next;
        ind->next = temp;
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode *itr, *ptr = new ListNode();
        ptr->next = head;
        head = ptr;
        ptr = ptr->next;

        while (ptr != NULL && ptr->next != NULL) {
            if (ptr->next->val >= ptr->val && (ptr->next->next == NULL || ptr->next->val <= ptr->next->next->val)) {
                ptr = ptr->next;
                continue;
            }

            itr = head;
            while (itr->next->val < ptr->next->val) itr = itr->next;
            insert(itr, ptr);
            if (itr == ptr) ptr = ptr->next;

            ListNode* temp = head;
        }

        itr = head;
        head = head->next;
        delete(itr);
        return head;
    }
};