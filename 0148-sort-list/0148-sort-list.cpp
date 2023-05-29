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
    ListNode* sortList(ListNode* head) {
        ListNode* ptr = head;
        vector<int> copy;

        while(ptr) {
            copy.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(copy.begin(), copy.end());

        ptr = head;
        int i = 0;

        while(ptr) {
            ptr->val = copy[i];
            ptr = ptr->next;
            i++;
        }
        return head;
    }
};