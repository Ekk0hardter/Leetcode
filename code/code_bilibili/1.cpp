#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s += s;  // 拼接字符串，模拟环形
    int maxLen = 0;
    int count = 1;
    for (int i = 1; i < 2 * n; ++i) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            maxLen = max(maxLen, count);
            count = 1;
        }
    }
    maxLen = max(maxLen, count);  // 处理最后一段连续相同字符
    // 由于是环形，结果不能超过原字符串长度
    cout << min(maxLen, n) << endl;
    return 0;
}