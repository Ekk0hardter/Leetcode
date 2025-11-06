#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> results; // 存储所有组的结果
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<bool> activated(n + 2, false);
        int cold_starts = 0;

        for (int i = 0; i < n; i++) {
            int pos = a[i];
            if (!activated[pos - 1] && !activated[pos + 1]) {
                if (i > 0) {
                    cold_starts++;
                }
            }
            activated[pos] = true;
        }

        results.push_back(cold_starts); // 存储结果
    }

    // 最后统一输出
    for (int res : results) {
        cout << res << '\n';
    }

    return 0;
}