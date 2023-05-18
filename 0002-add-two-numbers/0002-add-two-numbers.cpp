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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = new ListNode();
        int carry = 0;
        ListNode* l = ans;
        int n1, n2;

        while (l1 != NULL || l2 != NULL)
        {
            
            l->next = new ListNode();
            l = l->next;

            if (l1 == NULL) n1 = 0;
            else 
            {
                n1 = l1->val;
                l1 = l1->next;
            }

            if (l2 == NULL) n2 = 0;
            else 
            {
                n2 = l2->val;
                l2 = l2->next;
            }


            int temp = n1 + n2 + carry;
            l->val = temp%10;
            carry = temp/10;

            
        }

        if (carry != 0)
        {
            l->next = new ListNode();
            l = l->next;
            l->val = carry;
        }


        ans = ans->next;
        return ans;

    }
};