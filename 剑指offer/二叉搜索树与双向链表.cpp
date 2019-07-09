#include <iostream>
#include <stack>
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		if (!pRootOfTree)	return nullptr;
		stack <TreeNode *> s;
		TreeNode * root;
		TreeNode * p = pRootOfTree;
		TreeNode * pre = nullptr;
		bool isFirst = true;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p -> left;
			}
			p = s.top();
			s.pop();
			if (isFirst) {
				root = p;
				pre = root;
				isFirst = false;
			} else {
				pre -> right = p;
				p -> left = pre;
				pre = p;
			}
			p = p -> right;
		}
		return root;
    }
};
