#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1)    return pHead2;
        if (!pHead2)    return pHead1;
        ListNode * head = nullptr;
        if (pHead1 -> val <= pHead2 -> val) {
            head = pHead1;
            pHead1 = pHead1 -> next;
        } else {
            head = pHead2;
            pHead2 = pHead2 -> next;
        }
        ListNode * p = head;
        while (pHead1 && pHead2) {
            if (pHead1 -> val <= pHead2 -> val) {
                p -> next = pHead1;
                pHead1 = pHead1 -> next;
            } else {
                p -> next = pHead2;
                pHead2 = pHead2 -> next;
            }
            p = p -> next;
        }
        p -> next = pHead1 ? pHead1 : pHead2;
        if (pHead1) pHead1 -> next = nullptr;
        if (pHead2) pHead2 -> next = nullptr;
        return head;
    }
};

int main ()
{
    struct ListNode * L1 = new struct ListNode(1);
    struct ListNode * L2 = new struct ListNode(2);
    ListNode * p1 = L1;
    ListNode * p2 = L2;
    for (int i = 3; i <= 7; i += 2) {
        p1 -> next = new struct ListNode(i);
        p1 = p1 -> next;
    }
    for (int i = 4; i <= 8; i += 2) {
        p2 -> next = new struct ListNode(i);
        p2 = p2 -> next;
    }
    // cout << L1 -> next -> next -> next -> val;
    auto solve = new Solution;
    ListNode * res = solve -> Merge(L1, L2);
    for (int i = 0; i < 8; ++i) {
        cout << res -> val << endl;
        res = res -> next;
    }
    return 0;
}
