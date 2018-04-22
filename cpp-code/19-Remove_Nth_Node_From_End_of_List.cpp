/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针，一个走过n之后另一个启动
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *ptr1 = newhead, *ptr2 = newhead;
        for(;ptr1 != NULL; ptr1 = ptr1->next, n--)
        {
        	if(n < 0) ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
        return newhead->next;
    }
};

// 递归，返回到n+1层时开始删除操作
class Solution {
public:
	int remove(ListNode* node, int n) {
		if(node->next == NULL) return 1;
		int level = remove(node->next, n) + 1;
		if(level == n+1)
			node->next = node->next->next;
		return level;
	}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        remove(newhead, n);
        return newhead->next;
    }
};