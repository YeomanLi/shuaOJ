#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct SNode * PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S = new struct SNode;
    S -> Next = nullptr;
    return S;
}

bool isEmpty(Stack S)
{
    return nullptr == S -> Next;
}

bool Push(Stack S, ElementType X)
{
    Stack TmpCell = new struct SNode;
    TmpCell -> Data = X;
    TmpCell -> Next = nullptr;
    S -> Next = TmpCell;
    return true;
}

#define ERROR -1
ElementType Pop(Stack S)
{
    if (isEmpty(S)) {
        cout << "空栈" << endl;
        return ERROR;
    }
    Stack Top = S -> Next;
    ElementType TopElem = Top -> Data;
    S -> Next = Top -> Next;
    delete Top;
    return TopElem;
}

int main ()
{
    return 0;
}
