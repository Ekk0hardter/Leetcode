#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 二分查找第一个大于target的元素位置
int lowerBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// 二分查找最后一个小于target的元素位置
int upperBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> r_pos, e_pos, d_pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'r') {
            r_pos.push_back(i);
        } else if (s[i] == 'e') {
            e_pos.push_back(i);
        } else if (s[i] == 'd') {
            d_pos.push_back(i);
        }
    }

    long long sum_rd = 0;
    for (int r : r_pos) {
        for (int d : d_pos) {
            if (r < d) {
                int e_start = lowerBound(e_pos, r);
                int e_end = upperBound(e_pos, d);
                int e_count = 0;
                if (e_start <= e_end) {
                    e_count = e_end - e_start + 1;
                }
                sum_rd += (long long)e_count * (d - r);
            }
        }
    }

    cout << sum_rd * 2 << endl;

    return 0;
}