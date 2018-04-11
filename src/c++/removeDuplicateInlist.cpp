class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		ListNode *ans = new ListNode(INT_MIN);
		ListNode *ptr = ans;
		ans->next = head;
		ListNode *l = ans;
		ListNode *r = ans->next;
		while (r != NULL) {
			if (l != ans && l->val == r->val) {
				r = r->next;
			}
			else if(r->next != NULL && r->val == r->next->val){
				l = r;
				r = r->next->next;
			}
			else {
				ptr->next = r;
				ptr = ptr->next;
				l = r;
				r = r->next;
			}
		}
		ptr->next = NULL;
		return ans->next;
	}
};
