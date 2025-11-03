#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int OFFSET = 6000;
const int MAXN = 6000 * 2 + 10; // 范围：0到12000

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> facilities(n);
    for (int i = 0; i < n; i++) {
        cin >> facilities[i].first >> facilities[i].second;
    }

    // dp[i][j]：考虑前i个设施，总电力为j（减去偏移）的最小花费
    // 这里使用一维DP，并滚动数组优化（但n=3000，状态数12000，所以可以直接二维，但也可以一维）
    vector<int> dp(MAXN, INT_MAX);
    dp[OFFSET] = 0; // 初始状态：电力0，花费0

    for (int i = 0; i < n; i++) {
        int a = facilities[i].first;
        int cost = facilities[i].second;
        vector<int> new_dp = dp; // 不选当前设施

        for (int j = 0; j < MAXN; j++) {
            if (dp[j] == INT_MAX) continue;
            int new_j = j + a;
            if (new_j >= 0 && new_j < MAXN) {
                if (new_dp[new_j] > dp[j] + cost) {
                    new_dp[new_j] = dp[j] + cost;
                }
            }
        }
        dp = new_dp;
    }

    int target = OFFSET + 1;
    if (dp[target] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[target] << endl;
    }

    return 0;
}