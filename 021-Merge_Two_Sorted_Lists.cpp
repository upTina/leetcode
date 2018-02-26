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
        ListNode* head = new ListNode(0);
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* cur = head;
		while (p&&q) {
			if (p->val <= q->val) {
				cur->next = new ListNode(p->val);
				cur = cur->next;
				p = p->next;
			}else {
				cur->next = new ListNode(q->val);
				cur = cur->next;
				q = q->next;
			}
		}
		if (q) cur->next = q;
		if (p) cur->next = p;
		return head->next;
    }
};
//简单
