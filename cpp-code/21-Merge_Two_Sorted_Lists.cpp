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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *tmp = result;
        while(l1 != NULL || l2 != NULL)
        {
        	if(l2 == NULL || (l1 != NULL && l1->val <= l2->val))
        	{
        		tmp->next = l1;
        		l1 = l1->next;
        	} else {
        		tmp->next = l2;
        		l2 = l2->next;
        	}
        	tmp = tmp->next;
        }
        return result->next;
    }
};


// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val)
        {
        	l1->next = mergeTwoLists(l1->next, l2);
        	return l1;
        } else {
        	l2->next = mergeTwoLists(l1, l2->next);
        	return l2;
        }
    }
};
