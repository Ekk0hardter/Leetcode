#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXVAL = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> first(MAXVAL+1, INT_MAX);
        vector<int> last(MAXVAL+1, -1);
        vector<bool> exists(MAXVAL+1, false);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            exists[a[i]] = true;
            if (first[a[i]] == INT_MAX) {
                first[a[i]] = i;
            }
            last[a[i]] = i;
        }
        
        vector<int> vals;
        for (int i = 1; i <= MAXVAL; i++) {
            if (exists[i]) {
                vals.push_back(i);
            }
        }
        
        int m = vals.size();
        vector<int> dp(m, 0);
        int max_dp = 0;
        for (int i = 0; i < m; i++) {
            int x = vals[i];
            dp[i] = 1;
            if (i > 0) {
                int prev = vals[i-1];
                if (last[prev] < first[x]) {
                    dp[i] = dp[i-1] + 1;
                } else {
                    // 需要找到最大的j < i，满足last[vals[j]] < first[x]
                    int left = 0, right = i-1;
                    int pos = -1;
                    while (left <= right) {
                        int mid = (left + right) / 2;
                        if (last[vals[mid]] < first[x]) {
                            pos = mid;
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                    if (pos != -1) {
                        dp[i] = dp[pos] + 1;
                    }
                }
            }
            if (dp[i] > max_dp) {
                max_dp = dp[i];
            }
        }
        
        int ans = vals.size() - max_dp;
        cout << ans << "\n";
    }
    return 0;
}