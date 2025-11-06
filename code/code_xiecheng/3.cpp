#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> results;
    results.reserve(T);

    while (T--) {
        long long N, d;
        cin >> N >> d;

        long long q = N / d;
        long long r = N % d;

        long long M = 0;

        // 余数 0
        if (q > 0) M += 1;

        // 余数 d/2（d 为偶数）
        if (d % 2 == 0) {
            long long cnthalf = q + (r >= d / 2 ? 1 : 0);
            if (cnthalf > 0) M += 1;
        }

        // 其他配对
        long long pairs = (d - 1) / 2;
        M += q * pairs;
        M += min(r, pairs);

        long long K = M + 1;
        results.push_back(K);
    }

    // 统一输出
    for (long long res : results) {
        cout << res << '\n';
    }

    return 0;
}