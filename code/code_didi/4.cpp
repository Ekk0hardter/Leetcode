#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> results;
    
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n); // 使用long long防止溢出
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long cur = a[0]; // 当前的a1值
        priority_queue<long long> pq; // 最大堆
        for (int i = 1; i < n; i++) {
            pq.push(a[i]);
        }
        
        int count = 0;
        while (!pq.empty()) {
            long long top = pq.top();
            if (top < cur) {
                break; // 所有元素都小于cur，结束
            }
            pq.pop();
            count++;
            long long x = top / 2; // 向下取整
            cur += x;
            top -= x;
            if (top >= cur) {
                pq.push(top); // 如果操作后仍然大于等于cur，需要继续操作
            }
        }
        
        results.push_back(count);
    }
    
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}