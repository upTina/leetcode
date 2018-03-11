class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(0);
		ListNode*p, *q;
		new_head->next = head;
		p = new_head;
		q = new_head->next;
		while (q != NULL&&q->next != NULL) {
			p->next = q->next;
			q->next = q->next->next;
			p->next->next = q;
			p = q;
			q = q->next;
		}
		return new_head->next;
    }
};
//很简单，精髓还是在前面加一个头指针
