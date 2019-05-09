#include <iostream>
#include <cstring>
using namespace std;

string str;
char res[50][50];
int n1, n2, len;
int pos = 0;

int main () {
	freopen("in", "r", stdin);
	cin >> str;
	memset(res, ' ', sizeof(res));
	len = str.length() + 2;
	n1 = len / 3;
	n2 = n1 + len % 3;
	for (int i = 0; i < n1; ++i)	res[i][0] = str[pos++];
	for (int i = 1; i <= n2 - 2; ++i)	res[n1 - 1][i] = str[pos++];
	for (int i = n1 - 1; i >= 0; --i)	res[i][n2 - 1] = str[pos++];
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			cout << res[i][j];
		}
		cout << endl;
	}
	return 0;
}