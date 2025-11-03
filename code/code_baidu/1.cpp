#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // 输入数组长度
    vector<int> a(n);
    priority_queue<int> maxHeap; // 最大堆

    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // 输入数组元素
        maxHeap.push(a[i]); // 将元素加入最大堆
    }

    int minVal = *min_element(a.begin(), a.end()); // 计算初始最小值
    int operations = 0; // 操作计数

    while (!maxHeap.empty()) {
        int maxVal = maxHeap.top(); // 获取当前最大值
        if (maxVal <= 2 * minVal) {
            break; // 如果满足条件，退出循环
        }

        maxHeap.pop(); // 移除最大值
        // 分解最大值
        int x = maxVal / 2;
        int y = (maxVal + 1) / 2;

        maxHeap.push(x); // 将分解后的值插入堆
        maxHeap.push(y);
        minVal = min(minVal, x); // 更新最小值
        operations++; // 增加操作次数
    }

    cout << operations << endl; // 输出最少操作数
    return 0;
}