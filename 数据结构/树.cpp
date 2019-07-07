#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef int ElementType;
typedef struct TNode * Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void InOrderTraversal(BinTree BT)
{
    if (BT) {
        InOrderTraversal(Bt -> Left);
        cout << BT -> Data << endl;
        InOrderTraversal(BT -> Right);
    }
}

// 非递归实现中序遍历
void InOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    stack <BinTree> s;
    while (T || !s.empty()) {
        while (T) { /*一直向左并将沿途结点压入堆栈 */
            s.push(T);
            T = T -> Left;
        }
        if (!s.empty()) {
            T = s.top();    /*结点弹出堆栈 */
            s.pop();
            cout << T -> Data << endl;  /*访问（打印）结点 */
            T = T -> Right; /*转向右子树 */
        }
    }
}
/*
    非递归先序和中序唯一的区别在于第一次遇见结点就访问（打印）
 */

// 非递归实现先序遍历
void PreOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    stack <BinTree> s;
    while (T || !s.empty()) {
        while (T) { /*一直向左并将沿途结点压入堆栈 */
            cout << T -> Data << endl;  /*访问（打印）结点 */
            s.push(T);
            T = T -> Left;
        }
        if (!s.empty()) {
            T = s.top();    /*结点弹出堆栈 */
            s.pop();
            T = T -> Right; /*转向右子树 */
        }
    }
}

// 后序遍历略
void PostOrderTraversal(BinTree BT);

void LevelOrderTraversal(BinTree BT)
{
    queue <BinTree> q;
    if (!BT)    return;
    q.push(BT);
    while (!q.empty()) {
        BinTree T;
        T = q.front();
        q.pop();
        cout << T -> Data << endl;
        if (T -> Left)  q.push(T -> Left);
        if (T -> Right) q.push(T -> Right);
    }
}

int main ()
{
    return 0;
}
