#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int m = n / 2;
        vector<bool> diff(m);
        for (int i = 0; i < m; i++) {
            if (s[i] != s[n - 1 - i]) {
                diff[i] = true;
            } else {
                diff[i] = false;
            }
        }
        int ans = 0;
        bool inSegment = false;
        for (int i = 0; i < m; i++) {
            if (diff[i]) {
                if (!inSegment) {
                    ans++;
                    inSegment = true;
                }
            } else {
                inSegment = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}