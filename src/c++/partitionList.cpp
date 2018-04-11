//one pass solution
class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		ListNode *res = new ListNode(INT_MIN);
		res->next = head;
		ListNode *l = res;
		ListNode *r;
		while (l->next != NULL && l->next->val < x) {
			l = l->next;
		}
		r = l->next;
		while (l->next != NULL && r->next != NULL) {
			if (r->next->val >= x) {
				r = r->next;
			}
			else {
				ListNode *tmp;
				tmp = r->next;
				r->next = tmp->next;
				tmp->next = l->next;
				l->next = tmp;
				l = l->next;
			}
		}
		return res->next;
	}
};
