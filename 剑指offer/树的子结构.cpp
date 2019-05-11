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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
      bool res = false;
      if (NULL != pRoot1 && NULL != pRoot2) {
        if (pRoot1 -> val == pRoot2 -> val)
          res = checkSub(pRoot1, pRoot2);
        if (!res)
          res = HasSubtree(pRoot1 -> left, pRoot2);
        if (!res)
          res = HasSubtree(pRoot1 -> right, pRoot2);
      }
      return res;
    }

    bool checkSub(TreeNode * r1, TreeNode * r2) {
      if (NULL == r2) return true;
      if (NULL == r1) return false;
      if (r1 -> val != r2 -> val) return false;
      return checkSub(r1 -> left, r2 -> left) && checkSub(r1 -> right, r2 -> right);
    }
};