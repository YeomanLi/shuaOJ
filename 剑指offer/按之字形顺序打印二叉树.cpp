#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
      vector <vector <int>> res;
      if (nullptr == pRoot) return res;
      queue <TreeNode *> q;
      q.push(pRoot);
      bool leftToRight = true;
      while (!q.empty())
      {
        int thisSize = q.size();
        vector <int> level(thisSize);
        for (int i = 0; i < thisSize; ++i) {
          TreeNode * node = q.front();
          int index = leftToRight ? i : thisSize - 1 - i;
          level[index] = node -> val;
          if (nullptr != node -> left)  q.push(node -> left);
          if (nullptr != node -> right)  q.push(node -> right);
          q.pop();
        }
        leftToRight = !leftToRight;
        res.push_back(level);
      }
      return res;
    }
};
