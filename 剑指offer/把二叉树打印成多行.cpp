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
      while (!q.empty())
      {
        int thisLen = q.size();
        vector <int> level;
        while (thisLen--)
        {
          TreeNode * temp = q.front();
          level.push_back(temp -> val);
          if (nullptr != temp -> left)  q.push(temp -> left);
          if (nullptr != temp -> right)  q.push(temp -> right);
          q.pop();
        }
        res.push_back(level);
      }
      return res;
    }
};