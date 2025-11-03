#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int mask = 0;
    int count = 1;
    
    for (char c : s) {
        int bit = c - 'a';
        mask ^= (1 << bit);
        
        // 只有当当前状态本身有效时才继续
        if (__builtin_popcount(mask) > 1) {
            count++;
            mask = (1 << bit);  // 新段从当前字符开始
        }
    }
    cout << count << endl;
    return 0;
}