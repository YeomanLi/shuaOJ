#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef int ElementType;
const int MINDATA = -1e6;
const int MAX_SIZE = 20;
struct HNode {
  ElementType * Data;
  int Capacity;
  int Size;
};
typedef struct HNode * Heap;
typedef Heap MinHeap;

MinHeap CreateHeap (int max_size)
{
  MinHeap H = new struct HNode;
  H -> Data = new ElementType [max_size];
  H -> Capacity = max_size;
  H -> Size = 0;
  H -> Data[0] = MINDATA;
  return H;
}

ElementType DeleteMin (MinHeap H)
{
  ElementType MinItem = H -> Data[1];
  ElementType temp = H -> Data[H -> Size --];
  int parent, child;
  for (parent = 1; parent * 2 <= H -> Size; parent = child) {
    child = parent * 2;
    if (child != H -> Size && H -> Data[child + 1] < H -> Data[child])
      ++child;
    if (temp <= H -> Data[child]) break;
    else  H -> Data[parent] = H -> Data[child];
  }
  H -> Data[parent] = temp;
  return MinItem;
}

void PercDown (MinHeap H, int p)
{
  ElementType X = H -> Data[p];
  int parent, child;
  for (parent = p; parent * 2 <= H -> Size; parent = child) {
    child = parent * 2;
    if (child != H -> Size && H -> Data[child + 1] < H -> Data[child])
      ++child;
    if (X <= H -> Data[child])  break;
    else  H -> Data[parent] = H -> Data[child]; //  下滤
  }
  H -> Data[parent] = X;
}

void BuildHeap (MinHeap H)
{
  for (int i = H -> Size / 2; i > 0; --i)
    PercDown(H, i);
}

class Sort {
  private:
    /* data */
    vector <ElementType> raw;
    int size;

  public:
    Sort();
    void PrintRaw();
    void Bubble_Sort();
    void Selection_Sort();
    void Insertion_Sort();
    void Shell_Sort();
};

Sort :: Sort() {
  string str = "657842961";
  for (int i = 0; i < str.length(); ++i) {
    raw.push_back(str[i] - '0');
  }
  size = raw.size();
}

void Sort :: PrintRaw () {
  for (int i = 0; i < raw.size(); ++i) {
    cout << raw[i] << '\t';
  }
}

void Sort :: Bubble_Sort () {
  for (int i = size - 1; i > 0; --i) {
    bool noSwap = true;
    for (int j = 0; j < i; ++j) {
      if (raw[j] > raw[j + 1]) {
        noSwap = false;
        swap(raw[j], raw[j + 1]);
      }
    }
    if (noSwap) break;  //  全程无交换，说明已经有序了，退出
  }
}

void Sort :: Selection_Sort () {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (raw[i] > raw[j]) {
        swap(raw[i], raw[j]);
      }
    }
  }
}

/**
 * 最好的情况，本来就是顺序，那么只有摸牌的过程了，N的时间复杂度
 * 最差的情况，本来就是逆序，N平方的时间复杂度
 * */
void Sort :: Insertion_Sort () {
  for (int p = 1; p < size; ++p) {
    // 首先摸一张牌
    const ElementType temp = raw[p];
    int i;
    for (i = p; i > 0 && temp < raw[i - 1]; --i) {
      // 移出空位
      raw[i] = raw[i - 1];
    }
    // 新牌落位
    raw[i] = temp;
  }
}

void Sort :: Shell_Sort () {
  // 希尔增量序列
  for (int D = size / 2; D > 0; D /= 2) {
    // 接下来就是插入排序的过程了
    for (int P = D; P < size; ++P) {
      // 首先摸出一张牌
      const ElementType temp = raw[P];
      int i;
      for (i = P; i >= D && temp < raw[i - D]; i -= D) {
        raw[i] = raw[i - D];
      }
      raw[i] = temp;
    }
  }
}

int main () {
  auto sort = new Sort();
  // sort -> Bubble_Sort();
  // sort -> Selection_Sort();
  // sort -> Insertion_Sort();
  // sort -> Shell_Sort();
  // sort -> PrintRaw();
  // MinHeap I = CreateHeap(20);
  // I -> Data[1] = 20;
  // I -> Data[2] = 18;
  // I -> Data[3] = 24;
  // I -> Data[4] = 26;
  // I -> Data[5] = 2;
  // I -> Data[6] = 12;
  // I -> Size = 6;
  // BuildHeap(I);
  // for (int i = 1; i <= 6; ++i) {
  //   int thisMin = DeleteMin(I);
  //   cout << thisMin << endl;
  // }
  return 0;
}
