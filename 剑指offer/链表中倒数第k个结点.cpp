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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if (0 >= k || NULL == pListHead)  return NULL;
      ListNode * fast = pListHead;
      ListNode * slow = pListHead;
      while (fast) {
        fast = fast -> next;
        if (0 == --k) break;
      }
      // k并未减到0，说明超出链表长度了
      if (0 != k) return NULL;
      while (fast) {
        fast = fast -> next;
        slow = slow -> next;
      }
      return slow;
    }
};