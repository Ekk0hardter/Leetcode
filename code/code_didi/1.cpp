#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;  // 读取测试数据组数

    vector<int> results;  // 存储每组测试数据的结果

    while (T--) {
        int n;
        cin >> n;  // 读取数组大小
        vector<long long> a(n);  // 使用 long long 防止溢出
        for (int i = 0; i < n; ++i) {
            cin >> a[i];  // 读取数组元素
        }

        int ans = 0;  // 操作次数

        // 遍历数组，从第二个元素开始（索引 1）
        for (int i = 1; i < n; ++i) {
            // 当当前元素大于 a[0] 时，继续操作
            while (a[i] > a[0]) {
                long long x = a[i] / 2;  // 计算 x = floor(a[i] / 2)
                a[0] += x;  // a1 增加 x
                a[i] -= x;  // ai 减少 x
                ans++;  // 操作次数加 1
            }
        }

        results.push_back(ans);  // 保存当前测试数据的结果
    }

    // 一次性输出所有结果
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}