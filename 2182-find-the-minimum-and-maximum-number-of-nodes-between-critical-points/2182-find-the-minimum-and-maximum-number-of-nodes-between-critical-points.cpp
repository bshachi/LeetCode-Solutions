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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_ind = -1, last_ind = -1, i = 1, minimum = INT_MAX;
        bool first_crit_found = false;

        while (head != NULL) {
            if (head->next == NULL || head->next->next == NULL) break;
            if ((head->next->val > head->val && head->next->val > head->next->next->val) ||
                (head->next->val < head->val && head->next->val < head->next->next->val)) {

                if (!first_crit_found) {
                    first_crit_found = true;
                    first_ind = i;
                }
                else minimum = min(minimum, i - last_ind);
                last_ind = i;
            }
            head = head->next;
            i++;
        }

        int maximum = last_ind - first_ind;
        if (!maximum) return {-1,-1};
        return {minimum, maximum};
    }
};