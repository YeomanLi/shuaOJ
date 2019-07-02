#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct LNode * PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

#define ERROR nullptr
Position Find(List L, ElementType X)
{
    // p 指向 L 的第一个结点
    Position p = L;
    while (p && X != p -> Data)
        p = p -> Next;
    if (p)  return p;
    return ERROR;
}

// 在位置 P 之前插入元素
bool Insert(List L, ElementType X, Position P)
{
    Position pre;
    // 寻找位置 P 的前一个结点
    for (pre = L; pre && pre -> Next != P; pre = pre -> Next);
    if (nullptr == pre) {
        cout << "插入位置参数错误" << endl;
        return false;
    } else {
        Position tmp = new struct LNode;
        tmp -> Data = X;
        tmp -> Next = pre -> Next;
        pre -> Next = tmp;
        return true;
    }
}

bool Delete(List L, Position P)
{
    Position pre;
    // 寻找位置 P 的前一个结点
    for (pre = L; pre && pre -> Next != P; pre = pre -> Next);
    if (nullptr == pre || nullptr == P) {
        cout << "删除位置错误" << endl;
        return false;
    } else {
        pre -> Next = P -> Next;
        delete P;
        return true;
    }
}

int main ()
{
    return 0;
}
