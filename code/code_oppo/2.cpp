#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 500005;

long long pow26[MAXN];

void precompute_powers(int n) {
    pow26[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow26[i] = (pow26[i-1] * 26) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    precompute_powers(n);
    
    vector<vector<int>> queries(m, vector<int>(26));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            cin >> queries[i][j];
        }
    }
    
    vector<long long> results;
    results.reserve(m);
    
    for (const auto& b : queries) {
        vector<int> weight(26);
        for (int i = 0; i < 26; i++) {
            weight[i] = b[i];
        }
        
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int idx = c - 'a';
            int current_weight = weight[idx];
            int count_less = 0;
            for (int j = 0; j < 26; j++) {
                if (weight[j] < current_weight) {
                    count_less++;
                }
            }
            ans = (ans + (long long)count_less * pow26[n - i - 1]) % MOD;
        }
        results.push_back(ans);
    }
    
    for (const auto& result : results) {
        cout << result << "\n";
    }
    
    return 0;
}