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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector <int> res;
      queue <TreeNode *> q;
      if (nullptr != root)  q.push(root);
      TreeNode * p = root;
      while (!q.empty())
      {
        TreeNode * temp = q.front();
        if (nullptr != temp -> left)  q.push(temp -> left);
        if (nullptr != temp -> right)  q.push(temp -> right);
        res.push_back(temp -> val);
        q.pop();
      }
      return res;
    }
};