#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main ()
{
    freopen("in", "r", stdin);
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
        bool check = true;
        int cur = 0;
        vector <int> v(N);
        stack <int> s;
        // 保存输入的pop数组
        for (int j = 0; j < N; ++j) cin >> v[j];
        for (int j = 1; j <= N; ++j) {
            s.push(j);
            // 栈满，说明不符合，直接退出
            if (M < s.size()) {
                check = false;
                break;
            }
            // 一直pop直到栈顶元素和pop数组当前位置（cur）不等
            while (cur < v.size() && !s.empty() && s.top() == v[cur]) {
                s.pop();
                ++cur;
            }
        }
        if (!s.empty()) check = false;
        cout << (check ? "YES" : "NO") << endl;
    }
}

