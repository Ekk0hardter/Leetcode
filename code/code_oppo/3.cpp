#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> freq(n+1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        int threshold = (n + 1) / 2; // ceil(n/2)
        int count = 0;
        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq >= threshold) {
            count++;
        }
        
        vector<pair<int, int>> operations(m);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            operations[i] = {x, y};
        }
        
        for (int i = 0; i < m; i++) {
            int pos = operations[i].first - 1;
            int oldVal = a[pos];
            int newVal = operations[i].second;
            
            freq[oldVal]--;
            a[pos] = newVal;
            freq[newVal]++;
            
            if (freq[oldVal] + 1 == maxFreq) {
                maxFreq = *max_element(freq.begin(), freq.end());
            } else if (freq[newVal] > maxFreq) {
                maxFreq = freq[newVal];
            }
            // Alternatively, we can recompute maxFreq each time to be safe, since n is only 2000.
            // But for efficiency, we try to update without full scan when possible.
            // Actually, since n is small (<=2000), we can simply compute maxFreq from freq array each time.
            maxFreq = *max_element(freq.begin(), freq.end());
            
            if (maxFreq >= threshold) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    return 0;
}