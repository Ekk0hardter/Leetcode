#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    
    int x_count = count(s.begin(), s.end(), 'X');
    long long total = 1;
    for (int i = 0; i < x_count; i++) {
        total = (total * 2) % MOD;
    }
    
    if (k == 0) {
        cout << total << endl;
        return 0;
    }
    
    vector<long long> dp(n + 1, 0);
    vector<long long> prefix_sum(n + 1, 0);
    dp[0] = 1;
    prefix_sum[0] = 1;
    
    int last_w = -1;
    long long bad = 0;
    
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        if (c == 'W') {
            dp[i] = dp[i - 1];
            last_w = i - 1;
        } else if (c == 'B') {
            int l = max(0, i - k);
            if (l > last_w) {
                long long subtract = l == 0 ? 0 : prefix_sum[l - 1];
                if (l > 0 && s[l - 1] == 'X') {
                    subtract = (subtract * 2) % MOD;
                }
                dp[i] = (dp[i - 1] - subtract + MOD) % MOD;
            } else {
                dp[i] = dp[i - 1];
            }
        } else { // 'X'
            long long temp = dp[i - 1] * 2 % MOD;
            int l = max(0, i - k);
            if (l > last_w) {
                long long subtract = l == 0 ? 0 : prefix_sum[l - 1];
                if (l > 0 && s[l - 1] == 'X') {
                    subtract = (subtract * 2) % MOD;
                }
                temp = (temp - subtract + MOD) % MOD;
            }
            dp[i] = temp;
        }
        prefix_sum[i] = (prefix_sum[i - 1] + dp[i]) % MOD;
    }
    
    bad = dp[n];
    long long ans = (total - bad + MOD) % MOD;
    cout << ans << endl;
    
    return 0;
}