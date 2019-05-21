#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int res = 0;
vector <int> coupon;
vector <int> product;

int main () {
  freopen("in", "r", stdin);
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int temp;
    cin >> temp;
    coupon.push_back(temp);
  }
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    product.push_back(temp);
  }
  sort(coupon.begin(), coupon.end());
  sort(product.begin(), product.end());
  int i = 0, j = 0;
  while (i < M && j < N && 0 > coupon[i] && 0 > product[j]) {
    res += coupon[i] * product[j];
    ++i;
    ++j;
  }
  i = M - 1;
  j = N - 1;
  while (i >= 0 && j >= 0 && 0 <= coupon[i] && 0 <= product[j]) {
    res += coupon[i] * product[j];
    --i;
    --j;
  }
  cout << res << endl;
  return 0;
}
