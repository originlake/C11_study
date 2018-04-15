#include <iostream>
#include <string>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		ListNode *r = head;
		ListNode *l = head;
		ListNode *end;
		int len = 0;
		while (l != NULL) {
			if (l->next == NULL) end = l;
			len++;
			l = l->next;
		}
		if (!len) return head;
		k = k % len;
		if (k == 0) return head;
		while (k >= 0) {
			if (r->next == NULL) r = head;
			else r = r->next;
			k--;
		}
		l = head;
		while (r != NULL) {
			if (l->next == NULL) {
				l = head;
			}
			else l = l->next;
			r = r->next;
		}

		if (l->next != NULL) {
			end->next = head;
			head = l->next;
			l->next=NULL;
		}
		return head;
	}
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode *myhead = new ListNode(0);
		ListNode *ptr = myhead;
		myhead->next = head;
		int i = 0;
		//find the node before mth node
		while (i + 1 != m) {
			i++;
			ptr = ptr->next;
		}
		//pre: the node before mth node, l:mth node, tmpl:ptr's prior node, tmpr:ptr's next node.
		ListNode *pre = ptr, *l = ptr->next, *tmpl, *tmpr;
		ptr = ptr->next;
		tmpr = ptr->next;
		i++;
		while (i < n) {
			i++;
			tmpl = ptr;
			ptr = tmpr;
			tmpr = ptr->next;
			ptr->next = tmpl;
		}
		l->next = tmpr;
		pre->next = ptr;
		return myhead->next;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k <= 1) return head;
		int count = 0;
		ListNode *myhead = new ListNode(0);
		ListNode *ptr = myhead;
		myhead->next = head;
		//pre: the node before reverse , l:1st reverse node, tmpl:ptr's prior node, tmpr:ptr's next node.
		ListNode *pre = ptr;
		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
			if (count % k == 0) {
				ListNode *l = pre->next, *tmpl, *tmpr;
				int i = k-1;
				ptr = pre->next;
				tmpr = ptr->next;
				while (i-->0) {
					tmpl = ptr;
					ptr = tmpr;
					tmpr = ptr->next;
					ptr->next = tmpl;
				}
				l->next = tmpr;
				pre->next = ptr;
				ptr = l;
				pre = l;
			}
		}
		return myhead->next;
	}
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;
		ListNode *ptr = head, *tmpl, *tmpr;
		tmpr = ptr->next;
		ptr->next = NULL;
		while (tmpr != NULL) {
			tmpl = ptr;
			ptr = tmpr;
			tmpr = ptr->next;
			ptr->next = tmpl;
		}
		return ptr;
	}
};
