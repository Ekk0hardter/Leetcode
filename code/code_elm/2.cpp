#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b = a;
        reverse(b.begin(), b.end()); // 构造相似排列，这里采用反转的方式
        for (int num : b) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}