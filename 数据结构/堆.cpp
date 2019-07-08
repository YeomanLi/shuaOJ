#include <iostream>
using namespace std;

const int MAXDATA = 1e6;
const int MaxSize = 20;
typedef int ElementType;
typedef struct HNode * Heap;
struct HNode {
    ElementType * Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;

MaxHeap CreateHeap(int MaxSize)
{
    MaxHeap H = new struct HNode;
    H -> Data = new ElementType[MaxSize + 1];
    H -> Size = 0;
    H -> Capacity = MaxSize;
    H -> Data[0] = MAXDATA;
    return H;
}

bool isFull(MaxHeap H)
{
    return H -> Size == H -> Capacity;
}

bool isEmpty(MaxHeap H)
{
    return 0 == H -> Size;
}

bool Insert(MaxHeap H, ElementType X)
{
    if (isFull(H)) {
        cout << "最大堆已满" << endl;
        return false;
    }
    int i = ++ H -> Size;
    for ( ; H -> Data[i / 2] < X; i /= 2)
        H -> Data[i] = H -> Data[i / 2];
    H -> Data[i] = X;
    return true;
}

bool DeleteMax(MaxHeap H)
{
    if (isEmpty(H)) {
        cout << "最大堆已空" << endl;
        return false;
    }
    ElementType MaxItem = H -> Data[1];
    ElementType X = H -> Data[H -> Size--];
    int parent, child;
    for (parent = 1; parent * 2 <= H -> Size; parent = child) {
        child = parent * 2;
        // 选取左右孩子中最大的那一个
        if (child != H -> Size && H -> Data[child] < H -> Data[child + 1])
            ++child;
        // 比两个孩子都大，说明找到了位置
        if (X >= H -> Data[child])  break;
        else    H -> Data[parent] = H -> Data[child];   //  下滤
    }
    H -> Data[parent] = X;
    return MaxItem;
}

// 建造最大堆
void PercDown (MaxHeap H, int p)
{
    /*
        下滤：将 H 中以 H -> Data[p] 为根的子堆调整为最大堆
        和删除差不多
     */
    int parent, child;
    ElementType X;
    X = H -> Data[p];   //  取出根结点存放的值
    for (parent = p; parent * 2 <= H -> Size; parent = child) {
        child = parent * 2;
        if (child != H -> Size && H -> Data[child] < H -> Data[child + 1])
            ++child;
        if (X >= H -> Data[child])  break;
        else    H -> Data[parent] = H -> Data[child];
    }
    H -> Data[parent] = X;
}

void BuildHeap(MaxHeap H)
{
    int i;
    for (i = H -> Size / 2; i > 0; --i)
        PercDown(H, i);
}

int main ()
{
    // 直接插入，复杂度 NlogN
    MaxHeap H = CreateHeap(20);
    Insert(H, 20);
    Insert(H, 18);
    Insert(H, 24);
    Insert(H, 26);
    Insert(H, 2);
    Insert(H, 12);
    // 先建立完全二叉树，再调整，复杂度 N，树中各结点高度和
    MaxHeap I = CreateHeap(20);
    I -> Data[1] = 20;
    I -> Data[2] = 18;
    I -> Data[3] = 24;
    I -> Data[4] = 26;
    I -> Data[5] = 2;
    I -> Data[6] = 12;
    BuildHeap(I);
    for (int i = 0; i <= H -> Size; ++i)
        cout << H -> Data[i] << " " << I -> Data[i] << endl;
    return 0;
}
