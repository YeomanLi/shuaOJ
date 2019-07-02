/**
 * @author Yeoman Li
 * @email Yeoman_Li@Outlook.com
 * @create date 2019-07-02 08:58:03
 * @modify date 2019-07-02 08:58:03
 */

#include <iostream>
using namespace std;

int N;
int thisNum;
float maxSum = -0.5;
int thisSum = 0;
int first;
int last;
int ini;

int main ()
{
    freopen("in", "r", stdin);
    cin >> N;
    int arr[N + 1];
    for (int i = 0; i < N; ++i) cin >> arr[i];
    ini = arr[0];
    first = ini;
    last = arr[N - 1];
    for (int i = 0; i < N; ++i) {
        thisSum += arr[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
            last = arr[i];
            first = ini;
        }
        if (0 > thisSum) {
            thisSum = 0;
            ini = arr[i + 1];
        }
    }
    maxSum = 0 > maxSum ? 0 : maxSum;
    cout << maxSum << " " << first << " " << last << endl;
    return 0;
}
