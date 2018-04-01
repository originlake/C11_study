struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0),*p=&head;
		int res = 0, sum = 0;
		while (l1 || l2 || res) {
			sum = (l1 ? l1->val:0) + (l2 ? l2->val:0) + res;
			res = 0;
			if (sum > 9) {
				res = 1;
				sum -= 10;
			}
			p->next = new ListNode(sum);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return head.next;
	}
};