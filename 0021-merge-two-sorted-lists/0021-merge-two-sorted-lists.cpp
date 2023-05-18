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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode *ans, *l1, *l2, *temp = NULL, *temp2 = NULL;
        if (list1->val > list2->val)
        {
            ans = list2;
            l1 = list2;
            l2 = list1;
        }

        else 
        {
            ans = list1;
            l1 = list1;
            l2 = list2;
        }


        while (l1->next != NULL && l2 != NULL)
        {
            if (l1->next->val < l2->val)
            {
                l1 = l1->next;
                continue;
            }

            temp = l1->next;
            l1->next = l2;
            
            while (l2->next != NULL && temp->val > l2->next->val)
            {
                l2 = l2->next;
            }

            temp2 = l2->next;
            l2->next = temp;
            l2 = temp2;
            l1 = temp;
        }

        if (l1->next == NULL) l1->next = l2;
        return ans;
        
    }
};