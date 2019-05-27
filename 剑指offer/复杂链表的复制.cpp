#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
      // 首先复制每个节点
      cloneNodes(pHead);
      // 接着，复制sibling指针
      cloneRandom(pHead);
      // 然后，奇数节点为原链表，偶数节点为复制的链表
      return reconnectNodes(pHead);
    }

    void cloneNodes (RandomListNode * pHead) {
      RandomListNode * node = pHead;
      while (node) {
        RandomListNode * cloned = new RandomListNode(node -> label);
        cloned -> next = node -> next;
        node -> next = cloned;
        node = cloned -> next;
      }
    }

    void cloneRandom (RandomListNode * pHead) {
      RandomListNode * node = pHead;
      while (node) {
        RandomListNode * cloned = node -> next;
        if (node -> random)
          cloned -> random = node -> random -> next;
        node = cloned -> next;
      }
    }

    RandomListNode * reconnectNodes (RandomListNode * pHead) {
      RandomListNode * clonedHead = nullptr;
      RandomListNode * clonedNode = nullptr;
      RandomListNode * node = pHead;
      if (node) {
        clonedHead = node -> next;
        node -> next = clonedHead ->next;
        node = node -> next;
        clonedNode = clonedHead;
      }
      while (node) {
        clonedNode -> next = node -> next;
        clonedNode = clonedNode -> next;
        node -> next = clonedNode -> next;
        node = node -> next;
      }
      return clonedHead;
    }
};