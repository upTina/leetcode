class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode*head = new ListNode(0);
		ListNode*q = head;
		vector<ListNode*> p;
		for (int i = 0; i < lists.size(); i++)
			p.push_back(lists[i]);
		int min = 0;
		bool terminate = true;
		while (true) {
			terminate = true;
			for (int i = 0; i < lists.size(); i++) {
				if (p[i] != nullptr) {
					terminate = false;
					min = i;
					break;
				}
			}
			if (terminate)
				break;
			for (int i = 0; i < lists.size(); i++) {
				if (p[i]!=nullptr&&p[i]->val<p[min]->val) {
					min = i;
				}
			}
			q->next = p[min];
			p[min] = p[min]->next;
			q = q->next;
			
		}
		q->next = nullptr;
		return head->next;
	}
};
//合并k个链表，感觉和合并2个链表没什么区别，思路和很直观，也能通过。
