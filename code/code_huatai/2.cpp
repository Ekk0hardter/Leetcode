#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    int x, y;
    cin >> x >> y;
    // 处理x和y的顺序，确保x <= y（按顺时针方向）
    if (x > y) swap(x, y);
    x--; y--; // 转换为0-based索引
    long long clockwise = 0;
    for (int i = x; i < y; ++i) {
        clockwise += a[i];
    }
    long long counterClockwise = total - clockwise;
    cout << min(clockwise, counterClockwise) << endl;
    return 0;
}