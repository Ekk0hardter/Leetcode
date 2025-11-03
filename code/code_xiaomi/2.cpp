
#include <iostream>
#include <vector>
using namespace std;

struct TestCase {
    int n;
    int k;
    vector<int> a;
    int result;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<TestCase> testCases(t);

    // 一次性读取所有测试用例数据
    for (int i = 0; i < t; ++i) {
        cin >> testCases[i].n >> testCases[i].k;
        testCases[i].a.resize(testCases[i].n);
        for (int j = 0; j < testCases[i].n; ++j) {
            cin >> testCases[i].a[j];
        }
    }

    // 处理每个测试用例
    for (auto& tc : testCases) {
        int left = 0, right = tc.n - 1;
        tc.result = 0;
        int k = tc.k;
        while (k > 0 && left <= right) {
            if (k % 2 == 1) {
                // 攻击第一艘船
                tc.a[left]--;
                if (tc.a[left] == 0) {
                    tc.result++;
                    left++;
                }
            } else {
                // 攻击最后一艘船
                tc.a[right]--;
                if (tc.a[right] == 0) {
                    tc.result++;
                    right--;
                }
            }
            k--;
        }
    }

    // 一次性输出所有测试用例结果
    for (const auto& tc : testCases) {
        cout << tc.result << '\n';
    }

    return 0;
}