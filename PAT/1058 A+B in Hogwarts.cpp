#include <iostream>
using namespace std;

typedef long long ll;

int main () {
  freopen("in", "r", stdin);
  ll a, b, c, d, e, f;
  scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
  ll sum = (a + d) * 29 * 17 + (b + e) * 29 + c + f;
  cout << sum / (29 * 17) << ".";
  sum %= (29 * 17);
  cout << sum / 29 << "." << sum % 29;
  return 0;
}
