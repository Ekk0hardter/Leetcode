#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 判断一个数是否为质数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// 计算本质不同质因子的和
int sumOfPrimeFactors(int n) {
    if (n == 1) return 0;
    int sum = 0;
    // 处理 2 这个质因子
    if (n % 2 == 0) {
        sum += 2;
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    // 处理其他可能的质因子
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0 && isPrime(i)) {
            sum += i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    // 如果最后剩下的数大于 1，说明它本身是质因子
    if (n > 1) {
        sum += n;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int sum = sumOfPrimeFactors(n);
        if (sum % 2 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

