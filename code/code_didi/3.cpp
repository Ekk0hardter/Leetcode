#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n+1, vector<int>(n+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cin >> a[i][j];
            }
        }
        
        // dp[i][j]: 从(i,j)开始到离开能获得的最大价值
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); // 初始化0，方便边界处理
        
        // 从右下角开始倒推
        for (int i=n; i>=1; i--) {
            for (int j=n; j>=1; j--) {
                int down = 0, right = 0;
                if (i < n) down = dp[i+1][j];
                if (j < n) right = dp[i][j+1];
                // 不拿宝藏：向下 -> 得到down
                // 拿宝藏：向右 -> 得到a[i][j] + right
                dp[i][j] = max(down, a[i][j] + right);
            }
        }
        
        cout << dp[1][1] << endl;
    }
    return 0;
}