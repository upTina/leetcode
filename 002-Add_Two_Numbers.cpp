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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
		ListNode* p = res;
		int x = 0, y = 0, carry = 0;
		while (l1 || l2) {
			x = l1 ? l1->val : 0;
			y = l2 ? l2->val : 0;
			p->next = new ListNode((x + y + carry) % 10);
			carry = (x + y + carry) / 10;
			p = p->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (carry) p->next = new ListNode(1);
		return res->next;
    }
};
//算法很简单，但是通过这个题目，了解结构体中的构造函数，c++中如何用new创建链表节点，
