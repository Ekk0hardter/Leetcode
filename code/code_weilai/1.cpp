
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, x;
vector<int> a;

// 判断候选值mid是否可行
bool isPossible(int mid) {
    long long total = 0; // 用long long防止溢出
    for (int num : a) {
        if (num > mid) {
            // 计算需要的操作次数：向上取整 (num - mid + x - 1) / x
            total += (num - mid + x - 1) / x;
            if (total > k) {
                return false;
            }
        }
    }
    return total <= k;
}

int main() {
    cin >> n >> k >> x;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int left = *min_element(a.begin(), a.end());
    int right = *max_element(a.begin(), a.end());
    
    // 二分查找
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isPossible(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}