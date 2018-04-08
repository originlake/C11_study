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
};
