#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TNode * Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree FindMax(BinTree BST)
{
    if (BST)
        while (BST -> Right)    BST = BST -> Right;
    return BST;
}

Position FindMin(BinTree BST)
{
    if (BST)
        while (BST -> Left)     BST = BST -> Left;
    return BST;
}

BinTree Insert(BinTree BST, ElementType X)
{
    if (!BST) {
        BST = new struct TNode;
        BST -> Data = X;
        BST -> Left = BST -> Right = nullptr;
    } else {
        if (X > BST -> Data)
            BST -> Right = Insert(BST -> Right, X);
        else if (X < BST -> Data)
            BST -> Left = Insert(BST -> Left, X);
    }
    return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
    Position Tmp;
    if (!BST)
        cout << "要删除的元素未找到" << endl;
    else {
        if (X < BST -> Data)
            BST -> Left = Delete(BST -> Left, X);
        else if (X > BST -> Data)
            BST -> Right = Delete(BST -> Right, X);
        else {
            /*
                如果待删除结点有两个孩子
                那么找到左子树中最大的或者右子树中最小的结点替代这个结点
                因为这两个一定是最多只有一个孩子的结点
                这样，就转换为删除只有一个孩子结点或者叶子节点，也就是第二个判断
             */
            if (BST -> Left && BST -> Right) {
                Tmp = FindMin(BST -> Right);    //  找出右子树中最小结点
                BST -> Data = Tmp -> Data;      //  填充删除结点
                BST -> Right = Delete(BST -> Right, BST -> Data);   //  从右子树中删除最小元素
            /*
                只有一个孩子或者是叶子是结点
                直接将孩子挂上去
             */
            } else {
                Tmp = BST;
                if (!BST -> Left)
                    BST = BST -> Right;
                else
                    BST = BST -> Left;
                delete Tmp;
            }
        }
    }
    return BST;
}

int main ()
{
    return 0;
}
