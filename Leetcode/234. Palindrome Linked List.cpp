#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head -> next)
            return true;
        // 首先利用快慢指针找到链表的中点
        stack <int> s;
        ListNode * slow = head;
        ListNode * fast = head;
        s.push(slow -> val);
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            s.push(slow -> val);
        }
        // 说明链表长度为奇数，pop掉中点
        if (!fast -> next)
            s.pop();
        while (slow -> next) {
            slow = slow -> next;
            if (slow -> val != s.top()) {
                return false;
            }
            s.pop();
        }
        return true;
    }
};
