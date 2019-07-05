#include <iostream>
#include <stack>
using namespace std;

typedef struct LNode {
    int data;
    int addr;
    int nextAddr;
} List;
const int MAX_SIZE = 1e5;
int firstAddr, N, K;

void ReversePrint(List * list)
{
    stack <List> s;
    bool firstFlag = true;
    int start;
    int cnt = N / K;
    for (int i = 0; i < N; ++i) {
        // 判断后面的是否够反转
        if (!cnt) {
            // 所剩元素不够反转的了，那么记下当前位置并退出
            start = i;
            break;
        }
        if (K > s.size())   s.push(list[i]);
        if (K == s.size()) {
            while (!s.empty()) {
                List tempNode = s.top();
                s.pop();
                // 都要输出一次结点地址
                printf("%05d", tempNode.addr);
                // 如果不是首结点，那么再次输出当前地址
                if (firstFlag) {
                    firstFlag = false;
                } else {
                    printf("\n%05d", tempNode.addr);
                }
                // 接着输出当前结点数据
                cout << ' ' << tempNode.data << ' ';
            }
            --cnt;
        }
    }
    for (int i = start; i < N; ++i) {
        // 都要输出一次结点地址
        printf("%05d", list[i].addr);
        // 如果不是首结点，那么再次输出当前地址
        if (firstFlag) {
            firstFlag = false;
        } else {
            printf("\n%05d", list[i].addr);
        }
        cout << ' ' << list[i].data << ' ';
    }
    cout << "-1";
}

int main ()
{
    // freopen("in", "r", stdin);
    cin >> firstAddr >> N >> K;
    int dataArr[MAX_SIZE];
    int nextArr[MAX_SIZE];
    for (int i = 0; i < N; ++i) {
        int addr;
        cin >> addr;
        cin >> dataArr[addr] >> nextArr[addr];
    }
    List * list = new List[N + 1];
    list[0].addr = firstAddr;
    list[0].data = dataArr[firstAddr];
    list[0].nextAddr = nextArr[firstAddr];
    for (int i = 1; i < N; ++i) {
        int thisAddr = list[i - 1].nextAddr;
        list[i].addr = thisAddr;
        list[i].data = dataArr[thisAddr];
        list[i].nextAddr = nextArr[thisAddr];
    }
    ReversePrint(list);
    delete [] list;
    return 0;
}
