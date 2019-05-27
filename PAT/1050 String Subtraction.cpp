#include <iostream>
#include <cstring>
using namespace std;

int alphaSet[256] = { 0 };
char ini[100000];
char s[100000];

int main () {
  freopen("in", "r", stdin);
  char ch;
  cin.getline(ini, 100000);
  cin.getline(s, 100000);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    alphaSet[s[i]] = 1;
  }
  len = strlen(ini);
  for (int i = 0; i < len; ++i) {
    ch = ini[i];
    if (!alphaSet[ch])
      cout << ch;
  }
  return 0;
}
