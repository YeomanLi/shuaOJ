#include <iostream>
using namespace std;

int N;
int thisSum = 0;
int maxSum = -1e7;

int main ()
{
    freopen("in", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int thisNum;
        cin >> thisNum;
        thisSum += thisNum;
        thisSum = 0 > thisSum ? 0 : thisSum;
        maxSum = maxSum > thisSum ? maxSum : thisSum;
    }
    cout << maxSum << endl;
    return 0;
}