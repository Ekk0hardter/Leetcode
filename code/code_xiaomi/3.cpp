#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

bool check(int D, const vector<int>& h, int k) {
    int n = h.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs((ll)h[i] - h[j]) <= (ll)D * (i - j)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] >= n - k) {
            return true;
        }
    }
    return false;
}

int solve(int n, int k, const vector<int>& h) {
    if (k >= n - 1) {
        return 0;
    }
    ll left = 0, right = 2000000000;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (check(mid, h, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int T;
    cin >> T;
    vector<int> results;
    
    for (int i = 0; i < T; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for (int j = 0; j < n; j++) {
            cin >> h[j];
        }
        results.push_back(solve(n, k, h));
    }
    
    for (int i = 0; i < T; i++) {
        cout << results[i] << endl;
    }
    
    return 0;
}