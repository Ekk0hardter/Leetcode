#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 计算最大公约数（辅助函数）
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // 分组：将下标按 floor(n/(i+1)) 的值分组（i从0到n-1，对应原下标1到n）
        vector<vector<int>> groups;
        int current = -1;
        for (int i = 0; i < n; ++i) {
            int key = n / (i + 1); // 原下标是i+1，计算floor(n/(i+1))
            if (groups.empty() || key != current) {
                groups.emplace_back();
                current = key;
            }
            groups.back().push_back(a[i]);
        }
        
        // 对每个组计算gcd，并累加所有组的gcd乘以组大小
        long long sum = 0;
        for (auto& g : groups) {
            int gcd_val = g[0];
            for (int num : g) {
                gcd_val = gcd(gcd_val, num);
            }
            sum += (long long)gcd_val * g.size();
        }
        
        cout << sum << '\n';
    }
    
    return 0;
}