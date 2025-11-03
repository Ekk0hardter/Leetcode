#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 读取矩阵的行数 n 和列数 m
    int n, m;
    cin >> n >> m;

    // 用于存储矩阵所有元素的一维数组
    vector<int> elements;

    // 读取矩阵的元素，并将其存入一维数组
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            elements.push_back(num);
        }
    }

    // 对元素进行降序排序，这样大的元素会排在前面
    sort(elements.begin(), elements.end(), greater<int>());

    // 用于存储最终字典序最大的矩阵
    vector<vector<int>> result(n, vector<int>(m));

    // 用于遍历排序后的元素数组的索引
    int index = 0;

    // 按行优先的顺序填充结果矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = elements[index++];
        }
    }

    // 输出结果矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}