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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* p = head;
		int number = head->val;
		while (p->next!=NULL) {
			if (number == p->next->val)
				p->next = p->next->next;
			else {
				number = p->next->val;
				p = p->next;
			}
		}
		return head;
    }
};

//首先要判断head可能为空，其他很简单
