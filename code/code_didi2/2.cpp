#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll S = accumulate(a.begin(), a.end(), 0LL);
        sort(a.begin(), a.end());
        
        ll avg = S / n;
        ll r = S % n;
        ll target_min = avg;
        ll target_max = (r > 0) ? avg + 1 : avg;
        
        // 计算达到平衡需要的操作数
        ll need_remove = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > target_max) {
                need_remove += a[i] - target_max;
            } else {
                break;
            }
        }
        
        ll need_add = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < target_min) {
                need_add += target_min - a[i];
            } else {
                break;
            }
        }
        
        ll M = max(need_remove, need_add);
        
        if (m >= M) {
            cout << (r > 0 ? 1 : 0) << endl;
        } else {
            // 模拟前m次操作
            vector<ll> b = a;
            for (ll i = 0; i < m; i++) {
                auto max_it = max_element(b.begin(), b.end());
                auto min_it = min_element(b.begin(), b.end());
                (*max_it)--;
                (*min_it)++;
            }
            ll max_val = *max_element(b.begin(), b.end());
            ll min_val = *min_element(b.begin(), b.end());
            cout << max_val - min_val << endl;
        }
    }
    return 0;
}