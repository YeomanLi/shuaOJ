#include <iostream>
using namespace std;

typedef int Position;
typedef int ElementType;
struct SNode {
    ElementType * Data;
    Position Top;
    int MaxSize;
};
typedef struct SNode * Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = new struct SNode;
    S -> MaxSize = MaxSize;
    S -> Top = -1;
    S -> Data = new ElementType [MaxSize];
    return S;
}

bool isFull(Stack S)
{
    return S -> Top == S -> MaxSize - 1;
}

bool Push(Stack S, ElementType X)
{
    if (isFull(S)) {
        cout << "栈满" << endl;
        return false;
    }
    S -> Data[++(S -> Top)] = X;
    return true;
}

#define ERROR -1
ElementType Pop(Stack S)
{
    if (isFull(S)) {
        cout << "空栈" << endl;
        return ERROR;
    }
    return S -> Data[(S -> Top)--];
}

int main ()
{
    return 0;
}