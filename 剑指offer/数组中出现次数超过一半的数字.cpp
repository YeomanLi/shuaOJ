#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (!cnt) {
                res = numbers.at(i);
                cnt = 1;
            } else if (numbers.at(i) == res) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers.at(i) == res)
                ++cnt;
        }
        if (cnt * 2 < numbers.size())   res = 0;
        return res;
    }
};