#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    string inputStr;
    // 一次性读取所有输入
    getline(cin, inputStr);
    stringstream ss(inputStr);
    
    int T;
    ss >> T;
    vector<string> outputs;
    
    while (T--) {
        ll n, m;
        ss >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) ss >> a[i];
        ll S = accumulate(a.begin(), a.end(), 0LL);
        sort(a.begin(), a.end());
        
        ll avg = S / n;
        ll r = S % n;
        ll target_min = avg;
        ll target_max = (r > 0) ? avg + 1 : avg;
        
        ll need_remove = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > target_max) {
                need_remove += a[i] - target_max;
            } else {
                break;
            }
        }
        
        ll need_add = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < target_min) {
                need_add += target_min - a[i];
            } else {
                break;
            }
        }
        
        ll M = max(need_remove, need_add);
        
        if (m >= M) {
            outputs.push_back(to_string(r > 0 ? 1 : 0));
        } else {
            vector<ll> b = a;
            for (ll i = 0; i < m; i++) {
                auto max_it = max_element(b.begin(), b.end());
                auto min_it = min_element(b.begin(), b.end());
                (*max_it)--;
                (*min_it)++;
            }
            ll max_val = *max_element(b.begin(), b.end());
            ll min_val = *min_element(b.begin(), b.end());
            outputs.push_back(to_string(max_val - min_val));
        }
    }
    
    // 一次性输出所有结果
    for (const string& s : outputs) {
        cout << s << endl;
    }
    
    return 0;
}