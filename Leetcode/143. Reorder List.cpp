#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  void reorderList(ListNode* head) {
    if (!head || !head -> next || !head -> next -> next)
      return;
    ListNode * slow = head;
    ListNode * fast = head;
    // 首先找到链表的中点
    while (fast -> next && fast -> next -> next) {
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    // 接着将链表的后半部分逆转
    ListNode * p = slow -> next;
    ListNode * q = p -> next;
    slow -> next = nullptr;
    p -> next = nullptr;
    while (q) {
      ListNode * temp = q -> next;
      q -> next = p;
      p = q;
      q = temp;
    }
    // 将倒置后的后半部分链表一次插入前半部分
    q = head;
    while (q && p) {
      ListNode * temp = q -> next;
      q -> next = p;
      p = p -> next;
      q -> next -> next = temp;
      q = temp;
    }
  }
};