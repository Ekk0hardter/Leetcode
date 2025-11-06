#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;
int n, d[N], dia;
vector<int> g[N];

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d[1] = 0;
    dfs(1, 0);
    int a = max_element(d + 1, d + n + 1) - d;
    d[a] = 0;
    dfs(a, 0);
    int b = max_element(d + 1, d + n + 1) - d;
    dia = d[b];
    vector<int> da(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) da[i] = d[i];
    d[b] = 0;
    dfs(b, 0);
    vector<int> db(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) db[i] = d[i];
    
    vector<int> cnt(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        int m = max(da[i], db[i]);
        cnt[m + 1]++;
    }
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    
    for (int k = 1; k <= n; k++) {
        int ans = min(n, cnt[k] + 1);
        if (k > dia) ans = n;
        cout << ans << (k == n ? "\n" : " ");
    }
    
    return 0;
}