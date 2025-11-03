#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 树状数组计算逆序数
class Fenwick {
public:
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
    int rangeSum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

long long countInversions(vector<int>& a, vector<int>& b) {
    // a 是原数组, b 是目标排列
    int n = a.size();
    // 离散化
    vector<int> allvals = a;
    for (int x : b) allvals.push_back(x);
    sort(allvals.begin(), allvals.end());
    allvals.erase(unique(allvals.begin(), allvals.end()), allvals.end());
    
    auto getIdx = [&](int val) {
        return lower_bound(allvals.begin(), allvals.end(), val) - allvals.begin() + 1;
    };
    
    // 映射目标排列中每个值的位置
    vector<int> posInB(n + 1);
    for (int i = 0; i < n; i++) {
        posInB[getIdx(b[i])] = i + 1;
    }
    
    // 计算逆序数
    Fenwick fenw(n);
    long long inv = 0;
    for (int i = n - 1; i >= 0; i--) {
        int pos = posInB[getIdx(a[i])];
        inv += fenw.query(pos - 1);
        fenw.update(pos, 1);
    }
    return inv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 目标排列：排序后前半升序，后半降序
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    
    // 构造山峰：取排序后的数组，从最大值开始往后降序
    // 其实就是排序后，后半部分反转
    int peak = n - 1;
    while (peak > 0 && sorted[peak] == sorted[peak - 1]) peak--;
    // 目标排列
    vector<int> target = sorted;
    reverse(target.begin() + peak, target.end());
    
    long long ans = countInversions(a, target);
    cout << ans << endl;
    
    return 0;
}