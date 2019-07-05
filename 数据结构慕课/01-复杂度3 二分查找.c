#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X )
{
    Position Left = 0;
    Position Right = L -> Last;
    while (Left <= Right)
    {
        Position Mid = Left + (Right - Left) / 2;
        if (X == L -> Data[Mid])
            return Mid;
        else if (X < L -> Data[Mid])
            Right = Mid - 1;
        else
            Left = Mid + 1;
    }
    return NotFound;
}
