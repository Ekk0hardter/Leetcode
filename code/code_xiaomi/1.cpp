
  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool check(ll x, int n, const vector<ll>& a) {
    if (n == 1) {
        return x <= a[0];
    }
    
    ll c = (x - 1) / (2 * n - 2);
    ll r = (x - 1) % (2 * n - 2);
    
    vector<ll> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cnt[i] = c * (i == 0 || i == n-1 ? 1 : 2);
        if (r >= i) {
            cnt[i]++;
        }
        if (r >= 2 * n - 2 - i) {
            cnt[i]++;
        }
        if (cnt[i] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    vector<ll> results;
    
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n == 1) {
            results.push_back(min(k, a[0]));
            continue;
        }
        
        ll left = 0, right = k;
        while (left < right) {
            ll mid = (left + right + 1) / 2;
            if (check(mid, n, a)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        results.push_back(left);
    }
    
    for (ll res : results) {
        cout << res << endl;
    }
    
    return 0;
}