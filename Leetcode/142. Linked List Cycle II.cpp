#include <iostream>
using namespace std;

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
	ListNode * findMeeting(ListNode * head) {
		ListNode * slow = head;
		ListNode * fast = head;
		while (fast && fast -> next) {
			slow = slow -> next;
			fast = fast -> next -> next;
			if (slow == fast) {
				return fast;
			}
		}
		return nullptr;
	}
	
	
    ListNode *detectCycle(ListNode *head) {
        ListNode * p = findMeeting(head);
        if (nullptr == p) {
        	cout << "no cycle";
			return nullptr;
		}
		int index = 0;
		ListNode * q = head;
		while (p != q) {
			p = p -> next;
			q = q -> next;
			++ index;
		}
		cout << "tail connects to node index " << index;
		return p;
    }
};

int main () {
	return 0;
} 
