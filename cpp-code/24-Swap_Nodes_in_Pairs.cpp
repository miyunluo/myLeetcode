/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 循环从前往后进行，使用 current，current->next，current->next->next
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *current = newhead;
        while(current->next != NULL && current->next->next != NULL)
        {
        	ListNode *first = current->next;
        	ListNode *second = current->next->next;
        	first->next = second->next;
        	current->next = second;
        	current->next->next = first;
        	current = current->next->next;
        }
        return newhead->next;
    }
};