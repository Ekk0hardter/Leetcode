#include <iostream>
#include <string>
using namespace std;

bool checkValidString(string s) {
    int minLeft = 0, maxLeft = 0;
    for (char c : s) {
        if (c == '(') {
            minLeft++;
            maxLeft++;
        } else if (c == ')') {
            minLeft = max(minLeft - 1, 0); // 最小值不能为负
            maxLeft--;
            if (maxLeft < 0) { // 右括号过多，直接不合法
                return false;
            }
        } else { // '*'，可以视为'(', ')', 或空
            minLeft = max(minLeft - 1, 0);
            maxLeft++;
        }
    }
    return minLeft == 0; // 最终左括号能完全匹配
}

int main() {
    string s;
    cin >> s;
    cout << (checkValidString(s) ? "true" : "false") << endl;
    return 0;
}