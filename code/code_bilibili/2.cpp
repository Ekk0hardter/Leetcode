#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "81" << endl;
        return 0;
    }
    
    string result;
    // 前n-1个9
    result.append(n - 1, '9');
    // 一个8
    result += '8';
    // n-1个0
    result.append(n - 1, '0');
    // 一个1
    result += '1';
    
    cout << result << endl;
    return 0;
}