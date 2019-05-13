#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * 1 2 3 4 5
     * 4 5 3 2 1
     * 4 3 5 1 2
     * */

    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
      if (0 == pushV.size() || 0 == popV.size())
        return false;
      vector <int> v;
      int i = 0, j = 0;
      while (i < pushV.size())
      {
        v.push_back(pushV.at(i++));
        while (j < popV.size() && v.back() == popV.at(j))
        {
          ++j;
          v.pop_back();
        }
      }
      return v.empty();
    }
};

int main () {
  vector <int> pushV;
  vector <int> popV;
  for (int i = 1; i < 6; ++i) pushV.push_back(i);
  popV.push_back(4);
  popV.push_back(5);
  popV.push_back(3);
  popV.push_back(2);
  popV.push_back(1);
  // for (int i = 0; i < 5; ++i) cout << pushV[i]  << '\t';
  // cout << endl;
  // for (int i = 0; i < 5; ++i) cout << popV[i]  << '\t';
  auto solve = new Solution();
  cout << solve -> IsPopOrder(pushV, popV) << endl;
}
