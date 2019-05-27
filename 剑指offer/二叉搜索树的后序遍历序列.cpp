#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
      const int len = sequence.size();
      if (!len) return false;
      const int root = sequence.at(len - 1);
      vector <int> leftTree, rightTree;
      int pos = 0;
      // 左子树
      for (pos; pos < len && root > sequence[pos]; ++pos) {
        leftTree.push_back(sequence[pos]);
      }
      // 右子树，注意不要把根放进去
      for (pos; pos < len - 1; ++pos) {
        if (root < sequence[pos])
          rightTree.push_back(sequence[pos]);
          // 如果右边有比根小的元素，直接返回false
        else
          return false;
      }
      // 接下来递归判断左右子树是否也是搜索树
      bool checkLeft = true;
      bool checkRight = true;
      if (1 < leftTree.size())  checkLeft = VerifySquenceOfBST(leftTree);
      if (1 < rightTree.size())  checkRight = VerifySquenceOfBST(rightTree);
      return (checkLeft && checkRight);
    }
};