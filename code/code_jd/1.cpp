#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0); // 统计每个字母的出现次数
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
        }
    }
    // 若没有奇数次字符，段数为1；否则段数等于奇数次字符的种类数
    cout << (odd == 0 ? 1 : odd) << endl;
    return 0;
}