#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Plog {
    int a; // 点赞数
    int c; // 内容杂乱度
};

bool comparePlog(const Plog& x, const Plog& y) {
    return x.a < y.a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<long long> allResults;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<Plog> plogs(n);
        for (int i = 0; i < n; ++i) {
            cin >> plogs[i].a;
        }
        for (int i = 0; i < n; ++i) {
            cin >> plogs[i].c;
        }

        sort(plogs.begin(), plogs.end(), comparePlog);

        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
        int max_c = 0;
        // 修正：从j到i的元素需满足“a值连续且无重复间隔”，通过检查每个位置是否符合a[j-1] + (k-j) == a[k-1]（k为j到i的每个位置）
        for (int j = i; j >= 1; --j) {
            bool isContinuous = true;
            max_c = max(max_c, plogs[j - 1].c);
            // 检查j到i之间所有元素是否连续
            for (int k = j + 1; k <= i; ++k) {
                if (plogs[k - 1].a != plogs[j - 1].a + (k - j)) {
                    isContinuous = false;
                    break;
                }
                max_c = max(max_c, plogs[k - 1].c);
            }
            if (isContinuous) {
                dp[i] = min(dp[i], dp[j - 1] + max_c);
            }
        }
    }

        allResults.push_back(dp[n]);
    }

    for (long long res : allResults) {
        cout << res << endl;
    }

    return 0;
}
