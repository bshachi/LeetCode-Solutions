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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        ListNode* l = ans;
        int len = lists.size(), minimum, min_index;
        vector<int> empt;

        for (int i = 0; i<len; i++)
            if (lists[i] == NULL) {lists.erase(lists.begin() + i); i--; len--;}

        while (not(lists.empty())) {
            l->next = new ListNode();
            l = l->next;

            len = lists.size();
            minimum = lists[0]->val;
            min_index = 0;

            for (int i = 0; i<len; i++) {
                if (lists[i]->val < minimum) {
                    minimum = lists[i]->val;
                    min_index = i;
                }
            }

            l->val = minimum;

            lists[min_index] = lists[min_index]->next;
            if (lists[min_index] == NULL) lists.erase(lists.begin() + min_index); 
            if (lists.empty()) break;
        } 

        return ans->next;
    }
};