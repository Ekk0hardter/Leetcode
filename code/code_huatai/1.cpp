#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string dna;
    int len;
    cin >> dna >> len;
    
    int n = dna.size();
    double maxGcRatio = -1;
    string result;
    
    // 遍历所有长度为len的子串
    for (int i = 0; i <= n - len; ++i) {
        string substr = dna.substr(i, len);
        int gcCount = 0;
        for (char c : substr) {
            if (c == 'G' || c == 'C') {
                gcCount++;
            }
        }
        double ratio = (double)gcCount / len;
        // 更新最大GC比例和对应子串
        if (ratio > maxGcRatio) {
            maxGcRatio = ratio;
            result = substr;
        }
    }
    
    cout << result << endl;
    return 0;
}