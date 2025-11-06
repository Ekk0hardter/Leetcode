#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1); // 1-based
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    string s(n + 1, ' ');
    vector<int> lastPos(26, 0); // 字母最后出现的位置
    char nextChar = 'a';

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            s[i] = nextChar;
            lastPos[nextChar - 'a'] = i;
            nextChar++;
        } else {
            s[i] = s[a[i]];
            lastPos[s[i] - 'a'] = i;
        }
    }

    // 输出
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << '\n';

    return 0;
}