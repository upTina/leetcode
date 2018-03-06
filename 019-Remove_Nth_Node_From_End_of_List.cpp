class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *new_head = new ListNode(0);
		  new_head->next = head;
		  ListNode *p = new_head;
		  if (p == NULL) return NULL;
		  int num = 0;
		  while (p->next != NULL) {
			  num++;
		  	p = p->next;
  		}
  		n = num - n;
  		int i = 0;
  		p = new_head;
	  	while (i < n) {
	  		p = p->next;
	  		i++;
  		}
	  	p->next = p->next->next;
	  	return new_head->next;
    }
};
//在链表最前方设置一个头指针，可以让之后的元素操作方式更统一
