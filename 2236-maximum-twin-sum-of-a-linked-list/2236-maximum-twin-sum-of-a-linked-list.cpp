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
    int pairSum(ListNode* head) {
        ListNode* ptr = head;
        vector<int> v;
        while(ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }

        int max = 0, n = v.size();
        for (int i = 0; i < n/2; i++) {
            if (v[i] + v[n - 1 - i] > max) max = v[i] + v[n - 1 - i];
        }

        return max;
    }
};