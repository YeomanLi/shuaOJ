#include <iostream>
using namespace std;

int N, b;
int cnt = 0;
int arr[80] = { 0 };

int main () {
	cin >> N >> b;
	// 输入为0，直接返回
	if (!N) {
		cout << "Yes" << endl;
		cout << 0;
		return 0;
	}
	// 首先求出进制转换的数组
	while (N) {
		arr[cnt++] = N % b;
		N /= b;
	}
	// 进行首尾判断
	bool flag = true;
	for (int i = 0; i < cnt / 2; ++i) {
		if (arr[i] != arr[cnt - 1 - i]) {
			flag = false;
			break;
		}
	}
	cout << (flag? "Yes" : "No") << endl;
	cout << arr[cnt - 1];
	for (int i = cnt - 2; i >= 0; --i) {
		cout << " " << arr[i];
	}
	return 0;
}