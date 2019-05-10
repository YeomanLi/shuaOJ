/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode * findMeeting(ListNode * pHead) {
        if (NULL == pHead || NULL == pHead -> next)  return NULL;
        ListNode * slow = pHead -> next;
        ListNode * fast = slow -> next;
        while (NULL != fast && NULL != slow) {
            if (fast == slow)   return fast;
            slow = slow -> next;
            fast = fast -> next;
            if (fast -> next)   fast = fast -> next;
        }
        return NULL;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode * meetingNode = findMeeting(pHead);
        if (NULL == meetingNode)    return NULL;
        int cnt = 1;
        ListNode * p = meetingNode;
        while (p -> next != meetingNode) {
            p = p -> next;
            ++cnt;
        }
        p = pHead;
        ListNode * p2 = pHead;
        while (cnt--) {
            p2 = p2 -> next;
        }
        while (p != p2) {
            p = p -> next;
            p2 = p2 -> next;
        }
        return p;
    }
};

// 断链法
// class Solution {
// public:
//     ListNode* EntryNodeOfLoop(ListNode* pHead)
//     {
//         ListNode * res = pHead;
//         ListNode * p = pHead -> next;
//         if (!p) return NULL;
//         while (p) {
//             res -> next = NULL;
//             res = p;
//             p = p -> next;
//         }
//         return res;
//     }
// };