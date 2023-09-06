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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans (k,NULL);
        if (!head) return ans;

        int n = 1;
        for (ListNode* ptr = head; ptr->next; ptr = ptr->next) n++;

        int x = n / k;
        int extra = n % k;
        ans[0] = head;
        for (int i = 0; i < k-1 && head; i++) {
            for (int j = 0; j < x-1; j++) head = head->next;
            if (x && extra > 0) {
                head = head->next;
                extra--;
            }
            ans[i+1] = head->next;
            head->next = NULL;
            head = ans[i+1];
        }

        return ans;
    }
};