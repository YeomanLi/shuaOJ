#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector <string> res;
    vector<string> Permutation(string str) {
        if (str.empty() || 0 == str.length())
            return res;
        PermuHelper(str, 0);
        // 排序
        sort(res.begin(), res.end());
        return res;
    }
    void PermuHelper(string str, int start) {
        if (start == str.length() - 1)
            if (res.end() == std :: find(res.begin(), res.end(), str))
                res.push_back(str);
        for (int i = start; i < str.length(); ++i) {
            swapEl(str, start, i);
            PermuHelper(str, start + 1);
            swapEl(str, start, i);
        }
    }
    void swapEl(string & str, int i, int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
};

int main ()
{
    vector <string> res;
    auto solve = new Solution();
    res = solve -> Permutation("abc");
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
