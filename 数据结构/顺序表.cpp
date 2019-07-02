#include <iostream>
using namespace std;

const int MAXSIZE = 1e7;
typedef int Position;
typedef int ElementType;
struct LNode {
    ElementType Data[MAXSIZE];
    Position last;
};
typedef struct LNode * List;

List MakeEmpty ()
{
    List L;
    L = new struct LNode;
    L -> last = -1;
    return L;
}

#define ERROR -1
Position Find(List L, ElementType X)
{
    Position pos;
    while(pos <= L -> last && L -> Data[pos] != X)
        ++pos;
    if (pos > L -> last)    return ERROR;
    return pos;
}

bool Insert(List L, ElementType X, Position P)
{
    // 表已经满了，不能插入
    if (MAXSIZE - 1 == L -> last) {
        cout << "表满" << endl;
        return false;
    }
    // 检查插入位置的合法性
    if (0 > P || L -> last + 1 < P) {
        cout << "位置不合法" << endl;
        return false;
    }
    // 将位置 P 及以后的元素顺序向后移动
    for (Position i = L -> last; i >= P; --i)
        L -> Data[i + 1] = L -> Data[i];
    L -> Data[P] = X;
    L -> last++;
    return true;
}

bool Delete(List L, Position P)
{
    // 检查空表以及删除位置的合法性
    if (P > L -> last || 0 > P) {
        cout << "位置不合法" << endl;
        return false;
    }
    // 将位置 P + 1 及以后的元素顺序向前移动
    for (Position i = P; i < L -> last; ++i)
        L -> Data[i] = L -> Data[i + 1];
    L -> last--;
    return true;
}

int main ()
{
    struct LNode * List = MakeEmpty();
    Insert(List, 1, 0);
    Insert(List, 2, 1);
    Insert(List, 3, 2);
    Delete(List, 2);
    Delete(List, 4);
    cout << Find(List, 2);
    return 0;
}