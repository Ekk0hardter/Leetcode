#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 505;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        
        // dp[i][j]: 到达(i,j)时已经拿取的宝藏总价值
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        dp[1][1] = 0;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] == -1) continue;
                
                // 选择1: 不拿当前宝藏，只能向下
                if (i + 1 <= n + 1) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                }
                
                // 选择2: 拿当前宝藏，可以向下或向右
                int new_val = dp[i][j] + a[i][j];
                if (i + 1 <= n + 1) {
                    dp[i + 1][j] = max(dp[i + 1][j], new_val);
                }
                if (j + 1 <= n + 1) {
                    dp[i][j + 1] = max(dp[i][j + 1], new_val);
                }
            }
        }
        
        // 检查所有离开宫殿的方式
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dp[n + 1][j]);
        }
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i][n + 1]);
        }
        
        cout << ans << endl;
    }
    return 0;
}