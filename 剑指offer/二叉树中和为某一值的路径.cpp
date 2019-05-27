#include <iostream>
#include <vector>
using namespace std;

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector <vector <int>> res;
    vector <int> temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
      if (root) backTracking(root, expectNumber);
      return res;
    }

    void backTracking (TreeNode * root, int target) {
      temp.push_back(root -> val);
      target -= root -> val;
      if (!target && !root -> left && !root -> right) {
        res.push_back(temp);
      } else {
        if (root -> left) backTracking(root -> left, target);
        if (root -> right)  backTracking(root -> right, target);
      }
      // 回溯
      temp.pop_back();
    }
};