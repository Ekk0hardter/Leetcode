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
        int n, m;
        cin >> n >> m;
        vector<int> t(n);
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
        }

        // 确定差分数组的大小，需要覆盖所有可能的t_i和t_i + m - 1，以及修改后的可能范围
        const int MAX_RANGE = 5 * 2e5 + 2 * 2e5;
        vector<int> diff(MAX_RANGE + 2, 0);

        // 第一步：用差分数组统计所有昙花的开花区间
        for (int ti : t) {
            int l = ti;
            int r = ti + m - 1;
            diff[l]++;
            diff[r + 1]--;
        }

        // 第二步：计算前缀和，得到每个时刻的原始开花次数pre[i]
        vector<int> pre(MAX_RANGE + 2, 0);
        for (int i = 1; i <= MAX_RANGE; ++i) {
            pre[i] = pre[i - 1] + diff[i];
        }

        int max_ans = 0;
        // 第三步：遍历每一株昙花，假设修改它，计算此时的最大时刻数
        for (int i = 0; i < n; ++i) {
            int original_t = t[i];
            int L = original_t;
            int R = original_t + m - 1;
            int cnt_in_range = 0;

            // 计算原区间[L, R]内每个时刻的pre值，找到出现次数最多的那个值cnt_freq
            vector<int> freq(MAX_RANGE + 2, 0);
            int cnt_freq = 0;
            for (int j = L; j <= R; ++j) {
                freq[pre[j]]++;
                cnt_freq = max(cnt_freq, freq[pre[j]]);
            }

            // 调整这株昙花后，原区间[L, R]内的每个时刻的pre值会减1，统计这些时刻中pre[j]-1 == 0的数量
            int current = 0;
            for (int j = L; j <= R; ++j) {
                if (pre[j] - 1 == 0) {
                    current++;
                }
            }

            // 再统计区间外pre[j] == 1的数量（因为调整的是这一株，区间外的pre[j]不受影响）
            for (int j = 1; j <= MAX_RANGE; ++j) {
                if (j < L || j > R) {
                    if (pre[j] == 1) {
                        current++;
                    }
                }
            }

            max_ans = max(max_ans, current);
        }

        cout << max_ans << "\n";
    }
    return 0;
}