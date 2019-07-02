#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct Node * PtrToNode;
// 队列中的结点
struct Node
{
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode Position;
struct QNode
{
    Position Front, Rear;
    int MaxSize;
};
typedef struct QNode * Queue;

bool isEmpty(Queue Q)
{
    return nullptr == Q -> Front;
}

ElementType DeleteQ(Queue Q)
{
    Position FrontCell = Q -> Front;
    // 如果队列中只有一个元素，删除后队列置为空
    if (Q -> Front == Q -> Rear)
        Q -> Front = Q -> Rear = nullptr;
    else
        Q -> Front = Q -> Front -> Next;
    ElementType FrontEl = FrontCell -> Data;
    delete FrontCell;
    return FrontEl;
}

int main ()
{
    return 0;
}