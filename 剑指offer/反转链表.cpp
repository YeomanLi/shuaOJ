/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
      ListNode * front = pHead;
      ListNode * pre = NULL;
      ListNode * res = NULL;
      while (NULL != front) {
        ListNode * temp = front -> next;
        if (NULL == temp) res = front;
        front -> next = pre;
        pre = front;
        front = temp;
      }
      return res;
    }
};