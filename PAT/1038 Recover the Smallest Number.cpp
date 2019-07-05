#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main ()
{
    freopen("in", "r", stdin);
    int N;
    cin >> N;
    string * in = new string[N + 1];
    for (int i = 0; i < N; ++i) cin >> in[i];
    sort(in, in + N, [](string a, string b) {
        return a + b < b + a;
    });
    string res;
    for (int i = 0; i < N; ++i) res += in[i];
    while (0 != res.length() && '0' == res[0])
        res.erase(res.begin());
    if (!res.length())  res += '0';
    cout << res;
    delete [] in;
    return 0;
}
