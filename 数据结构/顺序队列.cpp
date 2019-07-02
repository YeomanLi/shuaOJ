#include <iostream>
using namespace std;

typedef int Position;
typedef int ElementType;
struct QNode
{
    ElementType * Data;
    Position Front, Rear;
    int MaxSize;
};
typedef struct QNode * Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = new struct QNode;
    Q -> MaxSize = MaxSize;
    Q -> Front = Q -> Rear = 0;
    Q -> Data = new ElementType [MaxSize];
    return Q;
}

bool isFull(Queue Q)
{
    return (Q -> Rear + 1) % Q -> MaxSize == Q -> Front;
}

bool isEmpty(Queue Q)
{
    return Q -> Rear == Q -> Front;
}

bool AddQ(Queue Q, ElementType X)
{
    if (isFull(Q)) {
        cout << "队列满" << endl;
        return false;
    }
    Q -> Rear = (Q -> Rear + 1) % Q -> MaxSize;
    Q -> Data[Q -> Rear] = X;
    return true;
}

ElementType DeleteQ(Queue Q)
{
    if (isEmpty(Q)) {
        cout << "空队列" << endl;
        return false;
    }
    Q -> Front = (Q -> Front + 1) % Q -> MaxSize;
    return Q -> Data[Q -> Front];
}

int main ()
{
    return 0;
}
