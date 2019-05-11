#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
      vector <int> res;
      int rows = matrix.size();
      int cols = matrix[0].size();
      int cnt = rows * cols;
      int left = 0, top = 0;
      int bottom = rows - 1;
      int right = cols - 1;
      while (true) {
        for (int i = left; i < right; ++i) {
          res.push_back(matrix[top][i]);
          --cnt;
          if (0 >= cnt) return res;
        }
        for (int i = top; i < bottom; ++i) {
          res.push_back(matrix[i][right]);
          --cnt;
          if (0 >= cnt) return res;
        }
        for (int i = right; i > 0; --i) {
          res.push_back(matrix[bottom][i]);
          --cnt;
          if (0 >= cnt) return res;
        }
        for (int i = bottom; i > 0; --i) {
          res.push_back(matrix[i][left]);
          --cnt;
          if (0 >= cnt) return res;
        }
        ++left;
        --right;
        ++top;
        --bottom;
      }
    }
};

int main () {
  int row = 3;
  int col = 4;
  auto solve = new Solution();
  vector <vector <int>> v(row);
  for (int i = 0; i < row; ++i) v[i].resize(col);
  int cnt = 0;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      v[i][j] = ++cnt;
    }
  }
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      cout << v[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  vector <int> res = solve -> printMatrix(v);
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << endl;
  }
  return 0;
}
